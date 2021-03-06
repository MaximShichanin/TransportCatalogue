// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: svg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_svg_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_svg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_svg_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_svg_2eproto;
namespace proto_svg {
class Color;
struct ColorDefaultTypeInternal;
extern ColorDefaultTypeInternal _Color_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
class RGB;
struct RGBDefaultTypeInternal;
extern RGBDefaultTypeInternal _RGB_default_instance_;
class RGBa;
struct RGBaDefaultTypeInternal;
extern RGBaDefaultTypeInternal _RGBa_default_instance_;
}  // namespace proto_svg
PROTOBUF_NAMESPACE_OPEN
template<> ::proto_svg::Color* Arena::CreateMaybeMessage<::proto_svg::Color>(Arena*);
template<> ::proto_svg::Point* Arena::CreateMaybeMessage<::proto_svg::Point>(Arena*);
template<> ::proto_svg::RGB* Arena::CreateMaybeMessage<::proto_svg::RGB>(Arena*);
template<> ::proto_svg::RGBa* Arena::CreateMaybeMessage<::proto_svg::RGBa>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto_svg {

// ===================================================================

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_svg.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit PROTOBUF_CONSTEXPR Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
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
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
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
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Point& from);
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
  void InternalSwap(Point* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_svg.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:proto_svg.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class RGB final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_svg.RGB) */ {
 public:
  inline RGB() : RGB(nullptr) {}
  ~RGB() override;
  explicit PROTOBUF_CONSTEXPR RGB(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RGB(const RGB& from);
  RGB(RGB&& from) noexcept
    : RGB() {
    *this = ::std::move(from);
  }

  inline RGB& operator=(const RGB& from) {
    CopyFrom(from);
    return *this;
  }
  inline RGB& operator=(RGB&& from) noexcept {
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
  static const RGB& default_instance() {
    return *internal_default_instance();
  }
  static inline const RGB* internal_default_instance() {
    return reinterpret_cast<const RGB*>(
               &_RGB_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(RGB& a, RGB& b) {
    a.Swap(&b);
  }
  inline void Swap(RGB* other) {
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
  void UnsafeArenaSwap(RGB* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RGB* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RGB>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RGB& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const RGB& from);
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
  void InternalSwap(RGB* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_svg.RGB";
  }
  protected:
  explicit RGB(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRFieldNumber = 1,
    kGFieldNumber = 2,
    kBFieldNumber = 3,
  };
  // uint32 r = 1;
  void clear_r();
  uint32_t r() const;
  void set_r(uint32_t value);
  private:
  uint32_t _internal_r() const;
  void _internal_set_r(uint32_t value);
  public:

  // uint32 g = 2;
  void clear_g();
  uint32_t g() const;
  void set_g(uint32_t value);
  private:
  uint32_t _internal_g() const;
  void _internal_set_g(uint32_t value);
  public:

  // uint32 b = 3;
  void clear_b();
  uint32_t b() const;
  void set_b(uint32_t value);
  private:
  uint32_t _internal_b() const;
  void _internal_set_b(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto_svg.RGB)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  uint32_t r_;
  uint32_t g_;
  uint32_t b_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class RGBa final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_svg.RGBa) */ {
 public:
  inline RGBa() : RGBa(nullptr) {}
  ~RGBa() override;
  explicit PROTOBUF_CONSTEXPR RGBa(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RGBa(const RGBa& from);
  RGBa(RGBa&& from) noexcept
    : RGBa() {
    *this = ::std::move(from);
  }

  inline RGBa& operator=(const RGBa& from) {
    CopyFrom(from);
    return *this;
  }
  inline RGBa& operator=(RGBa&& from) noexcept {
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
  static const RGBa& default_instance() {
    return *internal_default_instance();
  }
  static inline const RGBa* internal_default_instance() {
    return reinterpret_cast<const RGBa*>(
               &_RGBa_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(RGBa& a, RGBa& b) {
    a.Swap(&b);
  }
  inline void Swap(RGBa* other) {
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
  void UnsafeArenaSwap(RGBa* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RGBa* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RGBa>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RGBa& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const RGBa& from);
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
  void InternalSwap(RGBa* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_svg.RGBa";
  }
  protected:
  explicit RGBa(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRgbFieldNumber = 1,
    kOpacityFieldNumber = 2,
  };
  // .proto_svg.RGB rgb = 1;
  bool has_rgb() const;
  private:
  bool _internal_has_rgb() const;
  public:
  void clear_rgb();
  const ::proto_svg::RGB& rgb() const;
  PROTOBUF_NODISCARD ::proto_svg::RGB* release_rgb();
  ::proto_svg::RGB* mutable_rgb();
  void set_allocated_rgb(::proto_svg::RGB* rgb);
  private:
  const ::proto_svg::RGB& _internal_rgb() const;
  ::proto_svg::RGB* _internal_mutable_rgb();
  public:
  void unsafe_arena_set_allocated_rgb(
      ::proto_svg::RGB* rgb);
  ::proto_svg::RGB* unsafe_arena_release_rgb();

  // double opacity = 2;
  void clear_opacity();
  double opacity() const;
  void set_opacity(double value);
  private:
  double _internal_opacity() const;
  void _internal_set_opacity(double value);
  public:

  // @@protoc_insertion_point(class_scope:proto_svg.RGBa)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::proto_svg::RGB* rgb_;
  double opacity_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Color final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_svg.Color) */ {
 public:
  inline Color() : Color(nullptr) {}
  ~Color() override;
  explicit PROTOBUF_CONSTEXPR Color(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Color(const Color& from);
  Color(Color&& from) noexcept
    : Color() {
    *this = ::std::move(from);
  }

  inline Color& operator=(const Color& from) {
    CopyFrom(from);
    return *this;
  }
  inline Color& operator=(Color&& from) noexcept {
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
  static const Color& default_instance() {
    return *internal_default_instance();
  }
  enum ColorCase {
    kName = 1,
    kRgb = 2,
    kRgba = 3,
    COLOR__NOT_SET = 0,
  };

  static inline const Color* internal_default_instance() {
    return reinterpret_cast<const Color*>(
               &_Color_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(Color& a, Color& b) {
    a.Swap(&b);
  }
  inline void Swap(Color* other) {
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
  void UnsafeArenaSwap(Color* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Color* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Color>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Color& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Color& from);
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
  void InternalSwap(Color* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_svg.Color";
  }
  protected:
  explicit Color(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kRgbFieldNumber = 2,
    kRgbaFieldNumber = 3,
  };
  // string name = 1;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .proto_svg.RGB rgb = 2;
  bool has_rgb() const;
  private:
  bool _internal_has_rgb() const;
  public:
  void clear_rgb();
  const ::proto_svg::RGB& rgb() const;
  PROTOBUF_NODISCARD ::proto_svg::RGB* release_rgb();
  ::proto_svg::RGB* mutable_rgb();
  void set_allocated_rgb(::proto_svg::RGB* rgb);
  private:
  const ::proto_svg::RGB& _internal_rgb() const;
  ::proto_svg::RGB* _internal_mutable_rgb();
  public:
  void unsafe_arena_set_allocated_rgb(
      ::proto_svg::RGB* rgb);
  ::proto_svg::RGB* unsafe_arena_release_rgb();

  // .proto_svg.RGBa rgba = 3;
  bool has_rgba() const;
  private:
  bool _internal_has_rgba() const;
  public:
  void clear_rgba();
  const ::proto_svg::RGBa& rgba() const;
  PROTOBUF_NODISCARD ::proto_svg::RGBa* release_rgba();
  ::proto_svg::RGBa* mutable_rgba();
  void set_allocated_rgba(::proto_svg::RGBa* rgba);
  private:
  const ::proto_svg::RGBa& _internal_rgba() const;
  ::proto_svg::RGBa* _internal_mutable_rgba();
  public:
  void unsafe_arena_set_allocated_rgba(
      ::proto_svg::RGBa* rgba);
  ::proto_svg::RGBa* unsafe_arena_release_rgba();

  void clear_color_();
  ColorCase color__case() const;
  // @@protoc_insertion_point(class_scope:proto_svg.Color)
 private:
  class _Internal;
  void set_has_name();
  void set_has_rgb();
  void set_has_rgba();

  inline bool has_color_() const;
  inline void clear_has_color_();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union ColorUnion {
    constexpr ColorUnion() : _constinit_{} {}
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::proto_svg::RGB* rgb_;
    ::proto_svg::RGBa* rgba_;
  } color__;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint32_t _oneof_case_[1];

  friend struct ::TableStruct_svg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Point

// double x = 1;
inline void Point::clear_x() {
  x_ = 0;
}
inline double Point::_internal_x() const {
  return x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:proto_svg.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:proto_svg.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  y_ = 0;
}
inline double Point::_internal_y() const {
  return y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:proto_svg.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:proto_svg.Point.y)
}

// -------------------------------------------------------------------

// RGB

// uint32 r = 1;
inline void RGB::clear_r() {
  r_ = 0u;
}
inline uint32_t RGB::_internal_r() const {
  return r_;
}
inline uint32_t RGB::r() const {
  // @@protoc_insertion_point(field_get:proto_svg.RGB.r)
  return _internal_r();
}
inline void RGB::_internal_set_r(uint32_t value) {
  
  r_ = value;
}
inline void RGB::set_r(uint32_t value) {
  _internal_set_r(value);
  // @@protoc_insertion_point(field_set:proto_svg.RGB.r)
}

// uint32 g = 2;
inline void RGB::clear_g() {
  g_ = 0u;
}
inline uint32_t RGB::_internal_g() const {
  return g_;
}
inline uint32_t RGB::g() const {
  // @@protoc_insertion_point(field_get:proto_svg.RGB.g)
  return _internal_g();
}
inline void RGB::_internal_set_g(uint32_t value) {
  
  g_ = value;
}
inline void RGB::set_g(uint32_t value) {
  _internal_set_g(value);
  // @@protoc_insertion_point(field_set:proto_svg.RGB.g)
}

// uint32 b = 3;
inline void RGB::clear_b() {
  b_ = 0u;
}
inline uint32_t RGB::_internal_b() const {
  return b_;
}
inline uint32_t RGB::b() const {
  // @@protoc_insertion_point(field_get:proto_svg.RGB.b)
  return _internal_b();
}
inline void RGB::_internal_set_b(uint32_t value) {
  
  b_ = value;
}
inline void RGB::set_b(uint32_t value) {
  _internal_set_b(value);
  // @@protoc_insertion_point(field_set:proto_svg.RGB.b)
}

// -------------------------------------------------------------------

// RGBa

// .proto_svg.RGB rgb = 1;
inline bool RGBa::_internal_has_rgb() const {
  return this != internal_default_instance() && rgb_ != nullptr;
}
inline bool RGBa::has_rgb() const {
  return _internal_has_rgb();
}
inline void RGBa::clear_rgb() {
  if (GetArenaForAllocation() == nullptr && rgb_ != nullptr) {
    delete rgb_;
  }
  rgb_ = nullptr;
}
inline const ::proto_svg::RGB& RGBa::_internal_rgb() const {
  const ::proto_svg::RGB* p = rgb_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto_svg::RGB&>(
      ::proto_svg::_RGB_default_instance_);
}
inline const ::proto_svg::RGB& RGBa::rgb() const {
  // @@protoc_insertion_point(field_get:proto_svg.RGBa.rgb)
  return _internal_rgb();
}
inline void RGBa::unsafe_arena_set_allocated_rgb(
    ::proto_svg::RGB* rgb) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(rgb_);
  }
  rgb_ = rgb;
  if (rgb) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto_svg.RGBa.rgb)
}
inline ::proto_svg::RGB* RGBa::release_rgb() {
  
  ::proto_svg::RGB* temp = rgb_;
  rgb_ = nullptr;
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
inline ::proto_svg::RGB* RGBa::unsafe_arena_release_rgb() {
  // @@protoc_insertion_point(field_release:proto_svg.RGBa.rgb)
  
  ::proto_svg::RGB* temp = rgb_;
  rgb_ = nullptr;
  return temp;
}
inline ::proto_svg::RGB* RGBa::_internal_mutable_rgb() {
  
  if (rgb_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto_svg::RGB>(GetArenaForAllocation());
    rgb_ = p;
  }
  return rgb_;
}
inline ::proto_svg::RGB* RGBa::mutable_rgb() {
  ::proto_svg::RGB* _msg = _internal_mutable_rgb();
  // @@protoc_insertion_point(field_mutable:proto_svg.RGBa.rgb)
  return _msg;
}
inline void RGBa::set_allocated_rgb(::proto_svg::RGB* rgb) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete rgb_;
  }
  if (rgb) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(rgb);
    if (message_arena != submessage_arena) {
      rgb = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, rgb, submessage_arena);
    }
    
  } else {
    
  }
  rgb_ = rgb;
  // @@protoc_insertion_point(field_set_allocated:proto_svg.RGBa.rgb)
}

// double opacity = 2;
inline void RGBa::clear_opacity() {
  opacity_ = 0;
}
inline double RGBa::_internal_opacity() const {
  return opacity_;
}
inline double RGBa::opacity() const {
  // @@protoc_insertion_point(field_get:proto_svg.RGBa.opacity)
  return _internal_opacity();
}
inline void RGBa::_internal_set_opacity(double value) {
  
  opacity_ = value;
}
inline void RGBa::set_opacity(double value) {
  _internal_set_opacity(value);
  // @@protoc_insertion_point(field_set:proto_svg.RGBa.opacity)
}

// -------------------------------------------------------------------

// Color

// string name = 1;
inline bool Color::_internal_has_name() const {
  return color__case() == kName;
}
inline bool Color::has_name() const {
  return _internal_has_name();
}
inline void Color::set_has_name() {
  _oneof_case_[0] = kName;
}
inline void Color::clear_name() {
  if (_internal_has_name()) {
    color__.name_.Destroy();
    clear_has_color_();
  }
}
inline const std::string& Color::name() const {
  // @@protoc_insertion_point(field_get:proto_svg.Color.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline void Color::set_name(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_name()) {
    clear_color_();
    set_has_name();
    color__.name_.InitDefault();
  }
  color__.name_.Set( static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto_svg.Color.name)
}
inline std::string* Color::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:proto_svg.Color.name)
  return _s;
}
inline const std::string& Color::_internal_name() const {
  if (_internal_has_name()) {
    return color__.name_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void Color::_internal_set_name(const std::string& value) {
  if (!_internal_has_name()) {
    clear_color_();
    set_has_name();
    color__.name_.InitDefault();
  }
  color__.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Color::_internal_mutable_name() {
  if (!_internal_has_name()) {
    clear_color_();
    set_has_name();
    color__.name_.InitDefault();
  }
  return color__.name_.Mutable(      GetArenaForAllocation());
}
inline std::string* Color::release_name() {
  // @@protoc_insertion_point(field_release:proto_svg.Color.name)
  if (_internal_has_name()) {
    clear_has_color_();
    return color__.name_.Release();
  } else {
    return nullptr;
  }
}
inline void Color::set_allocated_name(std::string* name) {
  if (has_color_()) {
    clear_color_();
  }
  if (name != nullptr) {
    set_has_name();
    color__.name_.InitAllocated(name, GetArenaForAllocation());
  }
  // @@protoc_insertion_point(field_set_allocated:proto_svg.Color.name)
}

// .proto_svg.RGB rgb = 2;
inline bool Color::_internal_has_rgb() const {
  return color__case() == kRgb;
}
inline bool Color::has_rgb() const {
  return _internal_has_rgb();
}
inline void Color::set_has_rgb() {
  _oneof_case_[0] = kRgb;
}
inline void Color::clear_rgb() {
  if (_internal_has_rgb()) {
    if (GetArenaForAllocation() == nullptr) {
      delete color__.rgb_;
    }
    clear_has_color_();
  }
}
inline ::proto_svg::RGB* Color::release_rgb() {
  // @@protoc_insertion_point(field_release:proto_svg.Color.rgb)
  if (_internal_has_rgb()) {
    clear_has_color_();
    ::proto_svg::RGB* temp = color__.rgb_;
    if (GetArenaForAllocation() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    color__.rgb_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::proto_svg::RGB& Color::_internal_rgb() const {
  return _internal_has_rgb()
      ? *color__.rgb_
      : reinterpret_cast< ::proto_svg::RGB&>(::proto_svg::_RGB_default_instance_);
}
inline const ::proto_svg::RGB& Color::rgb() const {
  // @@protoc_insertion_point(field_get:proto_svg.Color.rgb)
  return _internal_rgb();
}
inline ::proto_svg::RGB* Color::unsafe_arena_release_rgb() {
  // @@protoc_insertion_point(field_unsafe_arena_release:proto_svg.Color.rgb)
  if (_internal_has_rgb()) {
    clear_has_color_();
    ::proto_svg::RGB* temp = color__.rgb_;
    color__.rgb_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Color::unsafe_arena_set_allocated_rgb(::proto_svg::RGB* rgb) {
  clear_color_();
  if (rgb) {
    set_has_rgb();
    color__.rgb_ = rgb;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto_svg.Color.rgb)
}
inline ::proto_svg::RGB* Color::_internal_mutable_rgb() {
  if (!_internal_has_rgb()) {
    clear_color_();
    set_has_rgb();
    color__.rgb_ = CreateMaybeMessage< ::proto_svg::RGB >(GetArenaForAllocation());
  }
  return color__.rgb_;
}
inline ::proto_svg::RGB* Color::mutable_rgb() {
  ::proto_svg::RGB* _msg = _internal_mutable_rgb();
  // @@protoc_insertion_point(field_mutable:proto_svg.Color.rgb)
  return _msg;
}

// .proto_svg.RGBa rgba = 3;
inline bool Color::_internal_has_rgba() const {
  return color__case() == kRgba;
}
inline bool Color::has_rgba() const {
  return _internal_has_rgba();
}
inline void Color::set_has_rgba() {
  _oneof_case_[0] = kRgba;
}
inline void Color::clear_rgba() {
  if (_internal_has_rgba()) {
    if (GetArenaForAllocation() == nullptr) {
      delete color__.rgba_;
    }
    clear_has_color_();
  }
}
inline ::proto_svg::RGBa* Color::release_rgba() {
  // @@protoc_insertion_point(field_release:proto_svg.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_color_();
    ::proto_svg::RGBa* temp = color__.rgba_;
    if (GetArenaForAllocation() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    color__.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::proto_svg::RGBa& Color::_internal_rgba() const {
  return _internal_has_rgba()
      ? *color__.rgba_
      : reinterpret_cast< ::proto_svg::RGBa&>(::proto_svg::_RGBa_default_instance_);
}
inline const ::proto_svg::RGBa& Color::rgba() const {
  // @@protoc_insertion_point(field_get:proto_svg.Color.rgba)
  return _internal_rgba();
}
inline ::proto_svg::RGBa* Color::unsafe_arena_release_rgba() {
  // @@protoc_insertion_point(field_unsafe_arena_release:proto_svg.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_color_();
    ::proto_svg::RGBa* temp = color__.rgba_;
    color__.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Color::unsafe_arena_set_allocated_rgba(::proto_svg::RGBa* rgba) {
  clear_color_();
  if (rgba) {
    set_has_rgba();
    color__.rgba_ = rgba;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto_svg.Color.rgba)
}
inline ::proto_svg::RGBa* Color::_internal_mutable_rgba() {
  if (!_internal_has_rgba()) {
    clear_color_();
    set_has_rgba();
    color__.rgba_ = CreateMaybeMessage< ::proto_svg::RGBa >(GetArenaForAllocation());
  }
  return color__.rgba_;
}
inline ::proto_svg::RGBa* Color::mutable_rgba() {
  ::proto_svg::RGBa* _msg = _internal_mutable_rgba();
  // @@protoc_insertion_point(field_mutable:proto_svg.Color.rgba)
  return _msg;
}

inline bool Color::has_color_() const {
  return color__case() != COLOR__NOT_SET;
}
inline void Color::clear_has_color_() {
  _oneof_case_[0] = COLOR__NOT_SET;
}
inline Color::ColorCase Color::color__case() const {
  return Color::ColorCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_svg

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
