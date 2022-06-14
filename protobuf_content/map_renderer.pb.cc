// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: map_renderer.proto

#include "map_renderer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace map_renderer_base {
PROTOBUF_CONSTEXPR MapRendererSettings::MapRendererSettings(
    ::_pbi::ConstantInitialized)
  : color_palette_()
  , bus_lable_offset_(nullptr)
  , stop_lable_offset_(nullptr)
  , underlayer_color_(nullptr)
  , width_(0)
  , height_(0)
  , padding_(0)
  , stop_radius_(0)
  , line_width_(0)
  , bus_lable_font_size_(0)
  , stop_lable_font_size_(0)
  , underlayer_width_(0){}
struct MapRendererSettingsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MapRendererSettingsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MapRendererSettingsDefaultTypeInternal() {}
  union {
    MapRendererSettings _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MapRendererSettingsDefaultTypeInternal _MapRendererSettings_default_instance_;
}  // namespace map_renderer_base
static ::_pb::Metadata file_level_metadata_map_5frenderer_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_map_5frenderer_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_map_5frenderer_2eproto = nullptr;

const uint32_t TableStruct_map_5frenderer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, width_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, height_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, padding_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, stop_radius_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, line_width_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, bus_lable_font_size_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, bus_lable_offset_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, stop_lable_font_size_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, stop_lable_offset_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, underlayer_color_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, underlayer_width_),
  PROTOBUF_FIELD_OFFSET(::map_renderer_base::MapRendererSettings, color_palette_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::map_renderer_base::MapRendererSettings)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::map_renderer_base::_MapRendererSettings_default_instance_._instance,
};

const char descriptor_table_protodef_map_5frenderer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022map_renderer.proto\022\021map_renderer_base\032"
  "\tsvg.proto\"\361\002\n\023MapRendererSettings\022\r\n\005wi"
  "dth\030\001 \001(\001\022\016\n\006height\030\002 \001(\001\022\017\n\007padding\030\003 \001"
  "(\001\022\023\n\013stop_radius\030\004 \001(\001\022\022\n\nline_width\030\005 "
  "\001(\001\022\033\n\023bus_lable_font_size\030\006 \001(\005\022*\n\020bus_"
  "lable_offset\030\007 \001(\0132\020.proto_svg.Point\022\034\n\024"
  "stop_lable_font_size\030\010 \001(\005\022+\n\021stop_lable"
  "_offset\030\t \001(\0132\020.proto_svg.Point\022*\n\020under"
  "layer_color\030\n \001(\0132\020.proto_svg.Color\022\030\n\020u"
  "nderlayer_width\030\013 \001(\001\022\'\n\rcolor_palette\030\014"
  " \003(\0132\020.proto_svg.Colorb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_map_5frenderer_2eproto_deps[1] = {
  &::descriptor_table_svg_2eproto,
};
static ::_pbi::once_flag descriptor_table_map_5frenderer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_map_5frenderer_2eproto = {
    false, false, 430, descriptor_table_protodef_map_5frenderer_2eproto,
    "map_renderer.proto",
    &descriptor_table_map_5frenderer_2eproto_once, descriptor_table_map_5frenderer_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_map_5frenderer_2eproto::offsets,
    file_level_metadata_map_5frenderer_2eproto, file_level_enum_descriptors_map_5frenderer_2eproto,
    file_level_service_descriptors_map_5frenderer_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_map_5frenderer_2eproto_getter() {
  return &descriptor_table_map_5frenderer_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_map_5frenderer_2eproto(&descriptor_table_map_5frenderer_2eproto);
namespace map_renderer_base {

// ===================================================================

class MapRendererSettings::_Internal {
 public:
  static const ::proto_svg::Point& bus_lable_offset(const MapRendererSettings* msg);
  static const ::proto_svg::Point& stop_lable_offset(const MapRendererSettings* msg);
  static const ::proto_svg::Color& underlayer_color(const MapRendererSettings* msg);
};

const ::proto_svg::Point&
MapRendererSettings::_Internal::bus_lable_offset(const MapRendererSettings* msg) {
  return *msg->bus_lable_offset_;
}
const ::proto_svg::Point&
MapRendererSettings::_Internal::stop_lable_offset(const MapRendererSettings* msg) {
  return *msg->stop_lable_offset_;
}
const ::proto_svg::Color&
MapRendererSettings::_Internal::underlayer_color(const MapRendererSettings* msg) {
  return *msg->underlayer_color_;
}
void MapRendererSettings::clear_bus_lable_offset() {
  if (GetArenaForAllocation() == nullptr && bus_lable_offset_ != nullptr) {
    delete bus_lable_offset_;
  }
  bus_lable_offset_ = nullptr;
}
void MapRendererSettings::clear_stop_lable_offset() {
  if (GetArenaForAllocation() == nullptr && stop_lable_offset_ != nullptr) {
    delete stop_lable_offset_;
  }
  stop_lable_offset_ = nullptr;
}
void MapRendererSettings::clear_underlayer_color() {
  if (GetArenaForAllocation() == nullptr && underlayer_color_ != nullptr) {
    delete underlayer_color_;
  }
  underlayer_color_ = nullptr;
}
void MapRendererSettings::clear_color_palette() {
  color_palette_.Clear();
}
MapRendererSettings::MapRendererSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  color_palette_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:map_renderer_base.MapRendererSettings)
}
MapRendererSettings::MapRendererSettings(const MapRendererSettings& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      color_palette_(from.color_palette_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_bus_lable_offset()) {
    bus_lable_offset_ = new ::proto_svg::Point(*from.bus_lable_offset_);
  } else {
    bus_lable_offset_ = nullptr;
  }
  if (from._internal_has_stop_lable_offset()) {
    stop_lable_offset_ = new ::proto_svg::Point(*from.stop_lable_offset_);
  } else {
    stop_lable_offset_ = nullptr;
  }
  if (from._internal_has_underlayer_color()) {
    underlayer_color_ = new ::proto_svg::Color(*from.underlayer_color_);
  } else {
    underlayer_color_ = nullptr;
  }
  ::memcpy(&width_, &from.width_,
    static_cast<size_t>(reinterpret_cast<char*>(&underlayer_width_) -
    reinterpret_cast<char*>(&width_)) + sizeof(underlayer_width_));
  // @@protoc_insertion_point(copy_constructor:map_renderer_base.MapRendererSettings)
}

inline void MapRendererSettings::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&bus_lable_offset_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&underlayer_width_) -
    reinterpret_cast<char*>(&bus_lable_offset_)) + sizeof(underlayer_width_));
}

MapRendererSettings::~MapRendererSettings() {
  // @@protoc_insertion_point(destructor:map_renderer_base.MapRendererSettings)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MapRendererSettings::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete bus_lable_offset_;
  if (this != internal_default_instance()) delete stop_lable_offset_;
  if (this != internal_default_instance()) delete underlayer_color_;
}

void MapRendererSettings::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void MapRendererSettings::Clear() {
// @@protoc_insertion_point(message_clear_start:map_renderer_base.MapRendererSettings)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  color_palette_.Clear();
  if (GetArenaForAllocation() == nullptr && bus_lable_offset_ != nullptr) {
    delete bus_lable_offset_;
  }
  bus_lable_offset_ = nullptr;
  if (GetArenaForAllocation() == nullptr && stop_lable_offset_ != nullptr) {
    delete stop_lable_offset_;
  }
  stop_lable_offset_ = nullptr;
  if (GetArenaForAllocation() == nullptr && underlayer_color_ != nullptr) {
    delete underlayer_color_;
  }
  underlayer_color_ = nullptr;
  ::memset(&width_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&underlayer_width_) -
      reinterpret_cast<char*>(&width_)) + sizeof(underlayer_width_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MapRendererSettings::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double width = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double height = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          height_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double padding = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          padding_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double stop_radius = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          stop_radius_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // double line_width = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 41)) {
          line_width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // int32 bus_lable_font_size = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          bus_lable_font_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto_svg.Point bus_lable_offset = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr = ctx->ParseMessage(_internal_mutable_bus_lable_offset(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 stop_lable_font_size = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 64)) {
          stop_lable_font_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto_svg.Point stop_lable_offset = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 74)) {
          ptr = ctx->ParseMessage(_internal_mutable_stop_lable_offset(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .proto_svg.Color underlayer_color = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          ptr = ctx->ParseMessage(_internal_mutable_underlayer_color(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double underlayer_width = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 89)) {
          underlayer_width_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // repeated .proto_svg.Color color_palette = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 98)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_color_palette(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<98>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MapRendererSettings::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:map_renderer_base.MapRendererSettings)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double width = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = this->_internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(1, this->_internal_width(), target);
  }

  // double height = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_height(), target);
  }

  // double padding = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = this->_internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_padding(), target);
  }

  // double stop_radius = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = this->_internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_stop_radius(), target);
  }

  // double line_width = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = this->_internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(5, this->_internal_line_width(), target);
  }

  // int32 bus_lable_font_size = 6;
  if (this->_internal_bus_lable_font_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(6, this->_internal_bus_lable_font_size(), target);
  }

  // .proto_svg.Point bus_lable_offset = 7;
  if (this->_internal_has_bus_lable_offset()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(7, _Internal::bus_lable_offset(this),
        _Internal::bus_lable_offset(this).GetCachedSize(), target, stream);
  }

  // int32 stop_lable_font_size = 8;
  if (this->_internal_stop_lable_font_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(8, this->_internal_stop_lable_font_size(), target);
  }

  // .proto_svg.Point stop_lable_offset = 9;
  if (this->_internal_has_stop_lable_offset()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(9, _Internal::stop_lable_offset(this),
        _Internal::stop_lable_offset(this).GetCachedSize(), target, stream);
  }

  // .proto_svg.Color underlayer_color = 10;
  if (this->_internal_has_underlayer_color()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(10, _Internal::underlayer_color(this),
        _Internal::underlayer_color(this).GetCachedSize(), target, stream);
  }

  // double underlayer_width = 11;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = this->_internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(11, this->_internal_underlayer_width(), target);
  }

  // repeated .proto_svg.Color color_palette = 12;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_color_palette_size()); i < n; i++) {
    const auto& repfield = this->_internal_color_palette(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(12, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:map_renderer_base.MapRendererSettings)
  return target;
}

size_t MapRendererSettings::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:map_renderer_base.MapRendererSettings)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .proto_svg.Color color_palette = 12;
  total_size += 1UL * this->_internal_color_palette_size();
  for (const auto& msg : this->color_palette_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .proto_svg.Point bus_lable_offset = 7;
  if (this->_internal_has_bus_lable_offset()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *bus_lable_offset_);
  }

  // .proto_svg.Point stop_lable_offset = 9;
  if (this->_internal_has_stop_lable_offset()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *stop_lable_offset_);
  }

  // .proto_svg.Color underlayer_color = 10;
  if (this->_internal_has_underlayer_color()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *underlayer_color_);
  }

  // double width = 1;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = this->_internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    total_size += 1 + 8;
  }

  // double height = 2;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = this->_internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    total_size += 1 + 8;
  }

  // double padding = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = this->_internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    total_size += 1 + 8;
  }

  // double stop_radius = 4;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = this->_internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    total_size += 1 + 8;
  }

  // double line_width = 5;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = this->_internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    total_size += 1 + 8;
  }

  // int32 bus_lable_font_size = 6;
  if (this->_internal_bus_lable_font_size() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_bus_lable_font_size());
  }

  // int32 stop_lable_font_size = 8;
  if (this->_internal_stop_lable_font_size() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_stop_lable_font_size());
  }

  // double underlayer_width = 11;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = this->_internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MapRendererSettings::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    MapRendererSettings::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MapRendererSettings::GetClassData() const { return &_class_data_; }

void MapRendererSettings::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<MapRendererSettings *>(to)->MergeFrom(
      static_cast<const MapRendererSettings &>(from));
}


void MapRendererSettings::MergeFrom(const MapRendererSettings& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:map_renderer_base.MapRendererSettings)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  color_palette_.MergeFrom(from.color_palette_);
  if (from._internal_has_bus_lable_offset()) {
    _internal_mutable_bus_lable_offset()->::proto_svg::Point::MergeFrom(from._internal_bus_lable_offset());
  }
  if (from._internal_has_stop_lable_offset()) {
    _internal_mutable_stop_lable_offset()->::proto_svg::Point::MergeFrom(from._internal_stop_lable_offset());
  }
  if (from._internal_has_underlayer_color()) {
    _internal_mutable_underlayer_color()->::proto_svg::Color::MergeFrom(from._internal_underlayer_color());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_width = from._internal_width();
  uint64_t raw_width;
  memcpy(&raw_width, &tmp_width, sizeof(tmp_width));
  if (raw_width != 0) {
    _internal_set_width(from._internal_width());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_height = from._internal_height();
  uint64_t raw_height;
  memcpy(&raw_height, &tmp_height, sizeof(tmp_height));
  if (raw_height != 0) {
    _internal_set_height(from._internal_height());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_padding = from._internal_padding();
  uint64_t raw_padding;
  memcpy(&raw_padding, &tmp_padding, sizeof(tmp_padding));
  if (raw_padding != 0) {
    _internal_set_padding(from._internal_padding());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_stop_radius = from._internal_stop_radius();
  uint64_t raw_stop_radius;
  memcpy(&raw_stop_radius, &tmp_stop_radius, sizeof(tmp_stop_radius));
  if (raw_stop_radius != 0) {
    _internal_set_stop_radius(from._internal_stop_radius());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_line_width = from._internal_line_width();
  uint64_t raw_line_width;
  memcpy(&raw_line_width, &tmp_line_width, sizeof(tmp_line_width));
  if (raw_line_width != 0) {
    _internal_set_line_width(from._internal_line_width());
  }
  if (from._internal_bus_lable_font_size() != 0) {
    _internal_set_bus_lable_font_size(from._internal_bus_lable_font_size());
  }
  if (from._internal_stop_lable_font_size() != 0) {
    _internal_set_stop_lable_font_size(from._internal_stop_lable_font_size());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_underlayer_width = from._internal_underlayer_width();
  uint64_t raw_underlayer_width;
  memcpy(&raw_underlayer_width, &tmp_underlayer_width, sizeof(tmp_underlayer_width));
  if (raw_underlayer_width != 0) {
    _internal_set_underlayer_width(from._internal_underlayer_width());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MapRendererSettings::CopyFrom(const MapRendererSettings& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:map_renderer_base.MapRendererSettings)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MapRendererSettings::IsInitialized() const {
  return true;
}

void MapRendererSettings::InternalSwap(MapRendererSettings* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  color_palette_.InternalSwap(&other->color_palette_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MapRendererSettings, underlayer_width_)
      + sizeof(MapRendererSettings::underlayer_width_)
      - PROTOBUF_FIELD_OFFSET(MapRendererSettings, bus_lable_offset_)>(
          reinterpret_cast<char*>(&bus_lable_offset_),
          reinterpret_cast<char*>(&other->bus_lable_offset_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MapRendererSettings::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_map_5frenderer_2eproto_getter, &descriptor_table_map_5frenderer_2eproto_once,
      file_level_metadata_map_5frenderer_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace map_renderer_base
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::map_renderer_base::MapRendererSettings*
Arena::CreateMaybeMessage< ::map_renderer_base::MapRendererSettings >(Arena* arena) {
  return Arena::CreateMessageInternal< ::map_renderer_base::MapRendererSettings >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
