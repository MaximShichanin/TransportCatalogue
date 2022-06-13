#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

namespace svg {

using namespace std::literals;

struct Rgb {
    Rgb(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : red(r), green(g), blue(b) {}
    virtual std::string GetColor() const {
        std::ostringstream oss;
        oss << std::to_string(red) << ',' << std::to_string(green) << ',' << std::to_string(blue);
        return oss.str();
    }
    uint8_t red, green, blue;
};

struct Rgba : public Rgb {
public:
    Rgba(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, double op = 1.0) : Rgb(r, g, b), opacity(op) {}
    
    std::string GetColor() const override {
        std::ostringstream oss;
        oss << Rgb::GetColor() << ',';
        oss /*<< std::setprecision(2)*/ << opacity;
        return oss.str();
    }
    double opacity;
};

struct Visitor {
    std::string operator()(std::string str) const {
        return str;
    }
    std::string operator()(Rgb rgb) const {
        return "rgb("s + rgb.GetColor() + ")"s;
    }
    std::string operator()(Rgba rgba) const {
        return "rgba("s + rgba.GetColor() + ")"s;
    }
};

using Color = std::variant<std::string, Rgb, Rgba>;
// Объявив в заголовочном файле константу со спецификатором inline,
// мы сделаем так, что она будет одной на все единицы трансляции,
// которые подключают этот заголовок.
// В противном случае каждая единица трансляции будет использовать свою копию этой константы
inline const Color NoneColor{"none"};

enum class StrokeLineCap {
    BUTT,
    ROUND,
    SQUARE,
};

std::ostream& operator<<(std::ostream& os, StrokeLineCap slc);

enum class StrokeLineJoin {
    ARCS,
    BEVEL,
    MITER,
    MITER_CLIP,
    ROUND,
};

std::ostream& operator<<(std::ostream& os, StrokeLineJoin slj);

struct Point {
    Point() = default;
    Point(double x, double y)
        : x(x)
        , y(y) {
    }
    double x = 0;
    double y = 0;
};

/*
 * Вспомогательная структура, хранящая контекст для вывода SVG-документа с отступами.
 * Хранит ссылку на поток вывода, текущее значение и шаг отступа при выводе элемента
 */
struct RenderContext {
    RenderContext(std::ostream& out)
        : out(out) {
    }

    RenderContext(std::ostream& out, int indent_step, int indent = 0)
        : out(out)
        , indent_step(indent_step)
        , indent(indent) {
    }

    RenderContext Indented() const {
        return {out, indent_step, indent + indent_step};
    }

    void RenderIndent() const {
        for (int i = 0; i < indent; ++i) {
            out.put(' ');
        }
    }

    std::ostream& out;
    int indent_step = 0;
    int indent = 0;
};

/*
 * Абстрактный базовый класс Object служит для унифицированного хранения
 * конкретных тегов SVG-документа
 * Реализует паттерн "Шаблонный метод" для вывода содержимого тега
 */
class Object {
public:
    void Render(const RenderContext& context) const;

    virtual ~Object() = default;

private:
    virtual void RenderObject(const RenderContext& context) const = 0;
};

class ObjectContainer {
public:
    template<typename OBJ>
    void Add(OBJ);
    
    virtual ~ObjectContainer() = default;
private:
    virtual void AddPtr(std::unique_ptr<Object>&&) = 0;
};
template<typename OBJ>
void ObjectContainer::Add(OBJ object) {
    AddPtr(std::make_unique<OBJ>(std::move(object)));
}

class Drawable {
public:
    virtual void Draw(ObjectContainer&) const = 0;
    
    virtual ~Drawable() = default;
};

template<typename Child>
class PathProps {
public:
    Child& SetFillColor(Color color) {
        obj_color_ = color;
        return AsChild();
    }
    Child& SetStrokeColor(Color color) {
        stroke_color_ = color;
        return AsChild();
    }
    Child& SetStrokeWidth(double width) {
        stroke_width_ = width;
        return AsChild();
    }
    Child& SetStrokeLineCap(StrokeLineCap line_cap) {
        line_cap_ = line_cap;
        return AsChild();
    }
    Child& SetStrokeLineJoin(StrokeLineJoin line_join) {
        line_join_ = line_join;
        return AsChild();
    }
protected:
    ~PathProps() {}
    void RenderAttrs(const RenderContext& out) const {
        using namespace std::literals;
        
        if(obj_color_ != std::nullopt) {
            out.out << "fill=\""sv << std::visit(Visitor(), *obj_color_) << '\"';
        }
        if(stroke_color_ != std::nullopt) {
            out.out << " stroke=\""sv << std::visit(Visitor(), *stroke_color_) << '\"';
        }
        if(stroke_width_ != std::nullopt) {
            out.out << " stroke-width=\""sv << *stroke_width_ << '\"';
        }
        if(line_cap_ != std::nullopt) {
            out.out << " stroke-linecap=\""sv << *line_join_ << '\"';
        }
        if(line_join_ != std::nullopt) {
            out.out << " stroke-linejoin=\""sv << *line_join_ << '\"';
        }
    }
private:
    std::optional<Color> obj_color_ = std::nullopt;
    std::optional<Color> stroke_color_ = std::nullopt;
    std::optional<double> stroke_width_ = std::nullopt;
    std::optional<StrokeLineCap> line_cap_ = std::nullopt;
    std::optional<StrokeLineJoin> line_join_ = std::nullopt;
    
    Child& AsChild() {
        return static_cast<Child&>(*this);
    }
};

/*
 * Класс Circle моделирует элемент <circle> для отображения круга
 * https://developer.mozilla.org/en-US/docs/Web/SVG/Element/circle
 */
class Circle final : public Object, public PathProps<Circle> {
public:
    Circle& SetCenter(Point center);
    Circle& SetRadius(double radius);
private:
    void RenderObject(const RenderContext& context) const override;

    Point center_;
    double radius_ = 1.0;
};

/*
 * Класс Polyline моделирует элемент <polyline> для отображения ломаных линий
 * https://developer.mozilla.org/en-US/docs/Web/SVG/Element/polyline
 */
class Polyline final : public Object, public PathProps<Polyline> {
public:
    // Добавляет очередную вершину к ломаной линии
    Polyline& AddPoint(Point point);

    /*
     * Прочие методы и данные, необходимые для реализации элемента <polyline>
     */
private:
    std::vector<Point> poly_;
    
    void RenderObject(const RenderContext& context) const override;
};

/*
 * Класс Text моделирует элемент <text> для отображения текста
 * https://developer.mozilla.org/en-US/docs/Web/SVG/Element/text
 */
class Text final : public Object, public PathProps<Text> {
public:
    // Задаёт координаты опорной точки (атрибуты x и y)
    Text& SetPosition(Point pos);

    // Задаёт смещение относительно опорной точки (атрибуты dx, dy)
    Text& SetOffset(Point offset);

    // Задаёт размеры шрифта (атрибут font-size)
    Text& SetFontSize(uint32_t size);

    // Задаёт название шрифта (атрибут font-family)
    Text& SetFontFamily(std::string font_family);

    // Задаёт толщину шрифта (атрибут font-weight)
    Text& SetFontWeight(std::string font_weight);

    // Задаёт текстовое содержимое объекта (отображается внутри тега text)
    Text& SetData(std::string data);

    // Прочие данные и методы, необходимые для реализации элемента <text>
private:
    Point text_pos_ = {0.0, 0.0};
    Point offset_ = {0.0, 0.0};
    uint32_t font_size_ = 1;
    std::string font_family_;
    std::string font_weight_;
    std::string content_;
    
    void RenderObject(const RenderContext& context) const override;
};

class Document : public ObjectContainer {
public:
    // Добавляет в svg-документ объект-наследник svg::Object
    void AddPtr(std::unique_ptr<Object>&& obj) override;

    // Выводит в ostream svg-представление документа
    void Render(std::ostream& out) const;

    // Прочие методы и данные, необходимые для реализации класса Document
private:
    std::vector<std::unique_ptr<Object>> obj_vault_;
};

}  // namespace svg
