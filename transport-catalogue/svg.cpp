#include "svg.h"

namespace svg {

using namespace std::literals;

std::ostream& operator<<(std::ostream& os, StrokeLineCap slc) {
    using namespace std::literals;
    
    switch(slc) {
        case StrokeLineCap::BUTT:
            os << "butt"sv;
            break;
        case StrokeLineCap::ROUND:
            os << "round"sv;
            break;
        case StrokeLineCap::SQUARE:
            os << "square"sv;
            break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, StrokeLineJoin slj) {
    using namespace std::literals;
    
    switch(slj) {
        case StrokeLineJoin::ARCS:
            os << "arcs"sv;
            break;
        case StrokeLineJoin::BEVEL:
            os << "bevel"sv;
            break;
        case StrokeLineJoin::MITER:
            os << "miter"sv;
            break;
        case StrokeLineJoin::MITER_CLIP:
            os << "miter-clip"sv;
            break;
        case StrokeLineJoin::ROUND:
            os << "round"sv;
            break;
    }
    return os;
}

void Object::Render(const RenderContext& context) const {
    context.RenderIndent();

    // Делегируем вывод тега своим подклассам
    RenderObject(context);

    context.out << std::endl;
}

// ---------- Circle ------------------

Circle& Circle::SetCenter(Point center)  {
    center_ = center;
    return *this;
}

Circle& Circle::SetRadius(double radius)  {
    radius_ = radius;
    return *this;
}

void Circle::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<circle cx=\""sv << center_.x << "\" cy=\""sv << center_.y << "\" "sv;
    out << "r=\""sv << radius_ << "\" "sv;
    RenderAttrs(context);
    out << "/>"sv;
}

// ---------- Polyline ------------------

Polyline& Polyline::AddPoint(Point point) {
    poly_.push_back(point);
    return *this;
}

void Polyline::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<polyline points=\""sv;
    for(auto iter = poly_.begin(); iter != poly_.end(); ++iter) {
        out << iter->x << ',' << iter->y;
        if(iter + 1 != poly_.end()) {
            out << ' ';
        }
    }
    out << "\" "sv;
    RenderAttrs(context);
    out << "/>"sv;
}

// ---------- Text ------------------

Text& Text::SetPosition(Point pos) {
    text_pos_ = pos;
    return *this;
}

Text& Text::SetOffset(Point offset) {
    offset_ = offset;
    return *this;
}

Text& Text::SetFontSize(uint32_t size) {
    font_size_ = size;
    return *this;
}

Text& Text::SetFontFamily(std::string font_family) {
    font_family_ = font_family;
    return *this;
}

Text& Text::SetFontWeight(std::string font_weight) {
    font_weight_ = font_weight;
    return *this;
}

Text& Text::SetData(std::string data) {
    for(char c : data) {
        switch(c) {
            case '\"':
                content_ += "&quot;"s;
                break;
            case '\'':
                content_ += "&apos;"s;
                break;
            case '<':
                content_ += "&lt;"s;
                break;
            case '>':
                content_ += "&gt;"s;
                break;
            case '&':
                content_ += "&amp;"s;
                break;
            default:
                content_.push_back(c);
                break;
        }
    }
    return *this;
}

void Text::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<text "sv; 
    RenderAttrs(context);
    out << " x=\""sv << text_pos_.x << "\" y=\""sv << text_pos_.y << "\""sv;
    out << " dx=\""sv << offset_.x << "\""sv << " dy=\""sv << offset_.y << "\""sv;
    out << " font-size=\""sv << font_size_ << "\""sv;
    if(!font_family_.empty()) {
        out << " font-family=\""sv << font_family_ << "\""sv;
    }
    if(!font_weight_.empty()) {
        out << " font-weight=\""sv << font_weight_ << "\""sv;
    }
    //RenderAttrs(context);
    out << ">"sv << content_ << "</text>"sv;
}

// ---------- Document ------------------

void Document::AddPtr(std::unique_ptr<Object>&& obj) {
    obj_vault_.push_back(std::move(obj));
}

void Document::Render(std::ostream& out) const {
    out << "<\?xml version=\"1.0\" encoding=\"UTF-8\" \?>\n"sv;
    out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n"sv;
    for(auto iter = obj_vault_.begin(); iter != obj_vault_.end(); ++iter) {
        iter->get()->Render(out);
    }
    out << "</svg>"sv;
}

}  // namespace svg
