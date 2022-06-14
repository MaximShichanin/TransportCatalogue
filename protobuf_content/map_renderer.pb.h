// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: map_renderer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "svg.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_map_5frenderer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_map_5frenderer_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_map_5frenderer_2eproto;
namespace map_renderer_base {
class MapRendererSettings;
struct MapRendererSettingsDefaultTypeInternal;
extern MapRendererSettingsDefaultTypeInternal _MapRendererSettings_default_instance_;
}  // namespace map_renderer_base
PROTOBUF_NAMESPACE_OPEN
template<> ::map_renderer_base::MapRendererSettings* Arena::CreateMaybeMessage<::map_renderer_base::MapRendererSettings>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace map_renderer_base {

// ===================================================================

class MapRendererSettings final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:map_renderer_base.MapRendererSettings) */ {
 public:
  inline MapRendererSettings() : MapRendererSettings(nullptr) {}
  ~MapRendererSettings() override;
  explicit PROTOBUF_CONSTEXPR MapRendererSettings(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MapRendererSettings(const MapRendererSettings& from);
  MapRendererSettings(MapRendererSettings&& from) noexcept
    : MapRendererSettings() {
    *this = ::std::move(from);
  }

  inline MapRendererSettings& operator=(const MapRendererSettings& from) {
    CopyFrom(from);
    return *this;
  }
  inline MapRendererSettings& operator=(MapRendererSettings&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MapRendererSettings& default_instance() {
    return *internal_default_instance();
  }
  static inline const MapRendererSettings* internal_default_instance() {
    return reinterpret_cast<const MapRendererSettings*>(
               &_MapRendererSettings_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MapRendererSettings& a, MapRendererSettings& b) {
    a.Swap(&b);
  }
  inline void Swap(MapRendererSettings* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MapRendererSettings* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MapRendererSettings* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MapRendererSettings>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MapRendererSettings& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const MapRendererSettings& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MapRendererSettings* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "map_renderer_base.MapRendererSettings";
  }
  protected:
  explicit MapRendererSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kColorPaletteFieldNumber = 12,
    kBusLableOffsetFieldNumber = 7,
    kStopLableOffsetFieldNumber = 9,
    kUnderlayerColorFieldNumber = 10,
    kWidthFieldNumber = 1,
    kHeightFieldNumber = 2,
    kPaddingFieldNumber = 3,
    kStopRadiusFieldNumber = 4,
    kLineWidthFieldNumber = 5,
    kBusLableFontSizeFieldNumber = 6,
    kStopLableFontSizeFieldNumber = 8,
    kUnderlayerWidthFieldNumber = 11,
  };
  // repeated .proto_svg.Color color_palette = 12;
  int color_palette_size() const;
  private:
  int _internal_color_palette_size() const;
  public:
  void clear_color_palette();
  ::proto_svg::Color* mutable_color_palette(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_svg::Color >*
      mutable_color_palette();
  private:
  const ::proto_svg::Color& _internal_color_palette(int index) const;
  ::proto_svg::Color* _internal_add_color_palette();
  public:
  const ::proto_svg::Color& color_palette(int index) const;
  ::proto_svg::Color* add_color_palette();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_svg::Color >&
      color_palette() const;

  // .proto_svg.Point bus_lable_offset = 7;
  bool has_bus_lable_offset() const;
  private:
  bool _internal_has_bus_lable_offset() const;
  public:
  void clear_bus_lable_offset();
  const ::proto_svg::Point& bus_lable_offset() const;
  PROTOBUF_NODISCARD ::proto_svg::Point* release_bus_lable_offset();
  ::proto_svg::Point* mutable_bus_lable_offset();
  void set_allocated_bus_lable_offset(::proto_svg::Point* bus_lable_offset);
  private:
  const ::proto_svg::Point& _internal_bus_lable_offset() const;
  ::proto_svg::Point* _internal_mutable_bus_lable_offset();
  public:
  void unsafe_arena_set_allocated_bus_lable_offset(
      ::proto_svg::Point* bus_lable_offset);
  ::proto_svg::Point* unsafe_arena_release_bus_lable_offset();

  // .proto_svg.Point stop_lable_offset = 9;
  bool has_stop_lable_offset() const;
  private:
  bool _internal_has_stop_lable_offset() const;
  public:
  void clear_stop_lable_offset();
  const ::proto_svg::Point& stop_lable_offset() const;
  PROTOBUF_NODISCARD ::proto_svg::Point* release_stop_lable_offset();
  ::proto_svg::Point* mutable_stop_lable_offset();
  void set_allocated_stop_lable_offset(::proto_svg::Point* stop_lable_offset);
  private:
  const ::proto_svg::Point& _internal_stop_lable_offset() const;
  ::proto_svg::Point* _internal_mutable_stop_lable_offset();
  public:
  void unsafe_arena_set_allocated_stop_lable_offset(
      ::proto_svg::Point* stop_lable_offset);
  ::proto_svg::Point* unsafe_arena_release_stop_lable_offset();

  // .proto_svg.Color underlayer_color = 10;
  bool has_underlayer_color() const;
  private:
  bool _internal_has_underlayer_color() const;
  public:
  void clear_underlayer_color();
  const ::proto_svg::Color& underlayer_color() const;
  PROTOBUF_NODISCARD ::proto_svg::Color* release_underlayer_color();
  ::proto_svg::Color* mutable_underlayer_color();
  void set_allocated_underlayer_color(::proto_svg::Color* underlayer_color);
  private:
  const ::proto_svg::Color& _internal_underlayer_color() const;
  ::proto_svg::Color* _internal_mutable_underlayer_color();
  public:
  void unsafe_arena_set_allocated_underlayer_color(
      ::proto_svg::Color* underlayer_color);
  ::proto_svg::Color* unsafe_arena_release_underlayer_color();

  // double width = 1;
  void clear_width();
  double width() const;
  void set_width(double value);
  private:
  double _internal_width() const;
  void _internal_set_width(double value);
  public:

  // double height = 2;
  void clear_height();
  double height() const;
  void set_height(double value);
  private:
  double _internal_height() const;
  void _internal_set_height(double value);
  public:

  // double padding = 3;
  void clear_padding();
  double padding() const;
  void set_padding(double value);
  private:
  double _internal_padding() const;
  void _internal_set_padding(double value);
  public:

  // double stop_radius = 4;
  void clear_stop_radius();
  double stop_radius() const;
  void set_stop_radius(double value);
  private:
  double _internal_stop_radius() const;
  void _internal_set_stop_radius(double value);
  public:

  // double line_width = 5;
  void clear_line_width();
  double line_width() const;
  void set_line_width(double value);
  private:
  double _internal_line_width() const;
  void _internal_set_line_width(double value);
  public:

  // int32 bus_lable_font_size = 6;
  void clear_bus_lable_font_size();
  int32_t bus_lable_font_size() const;
  void set_bus_lable_font_size(int32_t value);
  private:
  int32_t _internal_bus_lable_font_size() const;
  void _internal_set_bus_lable_font_size(int32_t value);
  public:

  // int32 stop_lable_font_size = 8;
  void clear_stop_lable_font_size();
  int32_t stop_lable_font_size() const;
  void set_stop_lable_font_size(int32_t value);
  private:
  int32_t _internal_stop_lable_font_size() const;
  void _internal_set_stop_lable_font_size(int32_t value);
  public:

  // double underlayer_width = 11;
  void clear_underlayer_width();
  double underlayer_width() const;
  void set_underlayer_width(double value);
  private:
  double _internal_underlayer_width() const;
  void _internal_set_underlayer_width(double value);
  public:

  // @@protoc_insertion_point(class_scope:map_renderer_base.MapRendererSettings)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_svg::Color > color_palette_;
  ::proto_svg::Point* bus_lable_offset_;
  ::proto_svg::Point* stop_lable_offset_;
  ::proto_svg::Color* underlayer_color_;
  double width_;
  double height_;
  double padding_;
  double stop_radius_;
  double line_width_;
  int32_t bus_lable_font_size_;
  int32_t stop_lable_font_size_;
  double underlayer_width_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_map_5frenderer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MapRendererSettings

// double width = 1;
inline void MapRendererSettings::clear_width() {
  width_ = 0;
}
inline double MapRendererSettings::_internal_width() const {
  return width_;
}
inline double MapRendererSettings::width() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.width)
  return _internal_width();
}
inline void MapRendererSettings::_internal_set_width(double value) {
  
  width_ = value;
}
inline void MapRendererSettings::set_width(double value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.width)
}

// double height = 2;
inline void MapRendererSettings::clear_height() {
  height_ = 0;
}
inline double MapRendererSettings::_internal_height() const {
  return height_;
}
inline double MapRendererSettings::height() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.height)
  return _internal_height();
}
inline void MapRendererSettings::_internal_set_height(double value) {
  
  height_ = value;
}
inline void MapRendererSettings::set_height(double value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.height)
}

// double padding = 3;
inline void MapRendererSettings::clear_padding() {
  padding_ = 0;
}
inline double MapRendererSettings::_internal_padding() const {
  return padding_;
}
inline double MapRendererSettings::padding() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.padding)
  return _internal_padding();
}
inline void MapRendererSettings::_internal_set_padding(double value) {
  
  padding_ = value;
}
inline void MapRendererSettings::set_padding(double value) {
  _internal_set_padding(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.padding)
}

// double stop_radius = 4;
inline void MapRendererSettings::clear_stop_radius() {
  stop_radius_ = 0;
}
inline double MapRendererSettings::_internal_stop_radius() const {
  return stop_radius_;
}
inline double MapRendererSettings::stop_radius() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.stop_radius)
  return _internal_stop_radius();
}
inline void MapRendererSettings::_internal_set_stop_radius(double value) {
  
  stop_radius_ = value;
}
inline void MapRendererSettings::set_stop_radius(double value) {
  _internal_set_stop_radius(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.stop_radius)
}

// double line_width = 5;
inline void MapRendererSettings::clear_line_width() {
  line_width_ = 0;
}
inline double MapRendererSettings::_internal_line_width() const {
  return line_width_;
}
inline double MapRendererSettings::line_width() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.line_width)
  return _internal_line_width();
}
inline void MapRendererSettings::_internal_set_line_width(double value) {
  
  line_width_ = value;
}
inline void MapRendererSettings::set_line_width(double value) {
  _internal_set_line_width(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.line_width)
}

// int32 bus_lable_font_size = 6;
inline void MapRendererSettings::clear_bus_lable_font_size() {
  bus_lable_font_size_ = 0;
}
inline int32_t MapRendererSettings::_internal_bus_lable_font_size() const {
  return bus_lable_font_size_;
}
inline int32_t MapRendererSettings::bus_lable_font_size() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.bus_lable_font_size)
  return _internal_bus_lable_font_size();
}
inline void MapRendererSettings::_internal_set_bus_lable_font_size(int32_t value) {
  
  bus_lable_font_size_ = value;
}
inline void MapRendererSettings::set_bus_lable_font_size(int32_t value) {
  _internal_set_bus_lable_font_size(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.bus_lable_font_size)
}

// .proto_svg.Point bus_lable_offset = 7;
inline bool MapRendererSettings::_internal_has_bus_lable_offset() const {
  return this != internal_default_instance() && bus_lable_offset_ != nullptr;
}
inline bool MapRendererSettings::has_bus_lable_offset() const {
  return _internal_has_bus_lable_offset();
}
inline const ::proto_svg::Point& MapRendererSettings::_internal_bus_lable_offset() const {
  const ::proto_svg::Point* p = bus_lable_offset_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto_svg::Point&>(
      ::proto_svg::_Point_default_instance_);
}
inline const ::proto_svg::Point& MapRendererSettings::bus_lable_offset() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.bus_lable_offset)
  return _internal_bus_lable_offset();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_bus_lable_offset(
    ::proto_svg::Point* bus_lable_offset) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(bus_lable_offset_);
  }
  bus_lable_offset_ = bus_lable_offset;
  if (bus_lable_offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_renderer_base.MapRendererSettings.bus_lable_offset)
}
inline ::proto_svg::Point* MapRendererSettings::release_bus_lable_offset() {
  
  ::proto_svg::Point* temp = bus_lable_offset_;
  bus_lable_offset_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto_svg::Point* MapRendererSettings::unsafe_arena_release_bus_lable_offset() {
  // @@protoc_insertion_point(field_release:map_renderer_base.MapRendererSettings.bus_lable_offset)
  
  ::proto_svg::Point* temp = bus_lable_offset_;
  bus_lable_offset_ = nullptr;
  return temp;
}
inline ::proto_svg::Point* MapRendererSettings::_internal_mutable_bus_lable_offset() {
  
  if (bus_lable_offset_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto_svg::Point>(GetArenaForAllocation());
    bus_lable_offset_ = p;
  }
  return bus_lable_offset_;
}
inline ::proto_svg::Point* MapRendererSettings::mutable_bus_lable_offset() {
  ::proto_svg::Point* _msg = _internal_mutable_bus_lable_offset();
  // @@protoc_insertion_point(field_mutable:map_renderer_base.MapRendererSettings.bus_lable_offset)
  return _msg;
}
inline void MapRendererSettings::set_allocated_bus_lable_offset(::proto_svg::Point* bus_lable_offset) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(bus_lable_offset_);
  }
  if (bus_lable_offset) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(bus_lable_offset));
    if (message_arena != submessage_arena) {
      bus_lable_offset = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, bus_lable_offset, submessage_arena);
    }
    
  } else {
    
  }
  bus_lable_offset_ = bus_lable_offset;
  // @@protoc_insertion_point(field_set_allocated:map_renderer_base.MapRendererSettings.bus_lable_offset)
}

// int32 stop_lable_font_size = 8;
inline void MapRendererSettings::clear_stop_lable_font_size() {
  stop_lable_font_size_ = 0;
}
inline int32_t MapRendererSettings::_internal_stop_lable_font_size() const {
  return stop_lable_font_size_;
}
inline int32_t MapRendererSettings::stop_lable_font_size() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.stop_lable_font_size)
  return _internal_stop_lable_font_size();
}
inline void MapRendererSettings::_internal_set_stop_lable_font_size(int32_t value) {
  
  stop_lable_font_size_ = value;
}
inline void MapRendererSettings::set_stop_lable_font_size(int32_t value) {
  _internal_set_stop_lable_font_size(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.stop_lable_font_size)
}

// .proto_svg.Point stop_lable_offset = 9;
inline bool MapRendererSettings::_internal_has_stop_lable_offset() const {
  return this != internal_default_instance() && stop_lable_offset_ != nullptr;
}
inline bool MapRendererSettings::has_stop_lable_offset() const {
  return _internal_has_stop_lable_offset();
}
inline const ::proto_svg::Point& MapRendererSettings::_internal_stop_lable_offset() const {
  const ::proto_svg::Point* p = stop_lable_offset_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto_svg::Point&>(
      ::proto_svg::_Point_default_instance_);
}
inline const ::proto_svg::Point& MapRendererSettings::stop_lable_offset() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.stop_lable_offset)
  return _internal_stop_lable_offset();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_stop_lable_offset(
    ::proto_svg::Point* stop_lable_offset) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(stop_lable_offset_);
  }
  stop_lable_offset_ = stop_lable_offset;
  if (stop_lable_offset) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_renderer_base.MapRendererSettings.stop_lable_offset)
}
inline ::proto_svg::Point* MapRendererSettings::release_stop_lable_offset() {
  
  ::proto_svg::Point* temp = stop_lable_offset_;
  stop_lable_offset_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto_svg::Point* MapRendererSettings::unsafe_arena_release_stop_lable_offset() {
  // @@protoc_insertion_point(field_release:map_renderer_base.MapRendererSettings.stop_lable_offset)
  
  ::proto_svg::Point* temp = stop_lable_offset_;
  stop_lable_offset_ = nullptr;
  return temp;
}
inline ::proto_svg::Point* MapRendererSettings::_internal_mutable_stop_lable_offset() {
  
  if (stop_lable_offset_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto_svg::Point>(GetArenaForAllocation());
    stop_lable_offset_ = p;
  }
  return stop_lable_offset_;
}
inline ::proto_svg::Point* MapRendererSettings::mutable_stop_lable_offset() {
  ::proto_svg::Point* _msg = _internal_mutable_stop_lable_offset();
  // @@protoc_insertion_point(field_mutable:map_renderer_base.MapRendererSettings.stop_lable_offset)
  return _msg;
}
inline void MapRendererSettings::set_allocated_stop_lable_offset(::proto_svg::Point* stop_lable_offset) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(stop_lable_offset_);
  }
  if (stop_lable_offset) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(stop_lable_offset));
    if (message_arena != submessage_arena) {
      stop_lable_offset = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, stop_lable_offset, submessage_arena);
    }
    
  } else {
    
  }
  stop_lable_offset_ = stop_lable_offset;
  // @@protoc_insertion_point(field_set_allocated:map_renderer_base.MapRendererSettings.stop_lable_offset)
}

// .proto_svg.Color underlayer_color = 10;
inline bool MapRendererSettings::_internal_has_underlayer_color() const {
  return this != internal_default_instance() && underlayer_color_ != nullptr;
}
inline bool MapRendererSettings::has_underlayer_color() const {
  return _internal_has_underlayer_color();
}
inline const ::proto_svg::Color& MapRendererSettings::_internal_underlayer_color() const {
  const ::proto_svg::Color* p = underlayer_color_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto_svg::Color&>(
      ::proto_svg::_Color_default_instance_);
}
inline const ::proto_svg::Color& MapRendererSettings::underlayer_color() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.underlayer_color)
  return _internal_underlayer_color();
}
inline void MapRendererSettings::unsafe_arena_set_allocated_underlayer_color(
    ::proto_svg::Color* underlayer_color) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(underlayer_color_);
  }
  underlayer_color_ = underlayer_color;
  if (underlayer_color) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_renderer_base.MapRendererSettings.underlayer_color)
}
inline ::proto_svg::Color* MapRendererSettings::release_underlayer_color() {
  
  ::proto_svg::Color* temp = underlayer_color_;
  underlayer_color_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto_svg::Color* MapRendererSettings::unsafe_arena_release_underlayer_color() {
  // @@protoc_insertion_point(field_release:map_renderer_base.MapRendererSettings.underlayer_color)
  
  ::proto_svg::Color* temp = underlayer_color_;
  underlayer_color_ = nullptr;
  return temp;
}
inline ::proto_svg::Color* MapRendererSettings::_internal_mutable_underlayer_color() {
  
  if (underlayer_color_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto_svg::Color>(GetArenaForAllocation());
    underlayer_color_ = p;
  }
  return underlayer_color_;
}
inline ::proto_svg::Color* MapRendererSettings::mutable_underlayer_color() {
  ::proto_svg::Color* _msg = _internal_mutable_underlayer_color();
  // @@protoc_insertion_point(field_mutable:map_renderer_base.MapRendererSettings.underlayer_color)
  return _msg;
}
inline void MapRendererSettings::set_allocated_underlayer_color(::proto_svg::Color* underlayer_color) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(underlayer_color_);
  }
  if (underlayer_color) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(underlayer_color));
    if (message_arena != submessage_arena) {
      underlayer_color = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, underlayer_color, submessage_arena);
    }
    
  } else {
    
  }
  underlayer_color_ = underlayer_color;
  // @@protoc_insertion_point(field_set_allocated:map_renderer_base.MapRendererSettings.underlayer_color)
}

// double underlayer_width = 11;
inline void MapRendererSettings::clear_underlayer_width() {
  underlayer_width_ = 0;
}
inline double MapRendererSettings::_internal_underlayer_width() const {
  return underlayer_width_;
}
inline double MapRendererSettings::underlayer_width() const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.underlayer_width)
  return _internal_underlayer_width();
}
inline void MapRendererSettings::_internal_set_underlayer_width(double value) {
  
  underlayer_width_ = value;
}
inline void MapRendererSettings::set_underlayer_width(double value) {
  _internal_set_underlayer_width(value);
  // @@protoc_insertion_point(field_set:map_renderer_base.MapRendererSettings.underlayer_width)
}

// repeated .proto_svg.Color color_palette = 12;
inline int MapRendererSettings::_internal_color_palette_size() const {
  return color_palette_.size();
}
inline int MapRendererSettings::color_palette_size() const {
  return _internal_color_palette_size();
}
inline ::proto_svg::Color* MapRendererSettings::mutable_color_palette(int index) {
  // @@protoc_insertion_point(field_mutable:map_renderer_base.MapRendererSettings.color_palette)
  return color_palette_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_svg::Color >*
MapRendererSettings::mutable_color_palette() {
  // @@protoc_insertion_point(field_mutable_list:map_renderer_base.MapRendererSettings.color_palette)
  return &color_palette_;
}
inline const ::proto_svg::Color& MapRendererSettings::_internal_color_palette(int index) const {
  return color_palette_.Get(index);
}
inline const ::proto_svg::Color& MapRendererSettings::color_palette(int index) const {
  // @@protoc_insertion_point(field_get:map_renderer_base.MapRendererSettings.color_palette)
  return _internal_color_palette(index);
}
inline ::proto_svg::Color* MapRendererSettings::_internal_add_color_palette() {
  return color_palette_.Add();
}
inline ::proto_svg::Color* MapRendererSettings::add_color_palette() {
  ::proto_svg::Color* _add = _internal_add_color_palette();
  // @@protoc_insertion_point(field_add:map_renderer_base.MapRendererSettings.color_palette)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_svg::Color >&
MapRendererSettings::color_palette() const {
  // @@protoc_insertion_point(field_list:map_renderer_base.MapRendererSettings.color_palette)
  return color_palette_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace map_renderer_base

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_map_5frenderer_2eproto
