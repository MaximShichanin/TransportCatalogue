// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transport_router.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_transport_5frouter_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_transport_5frouter_2eproto

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
#include "graph.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_transport_5frouter_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_transport_5frouter_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transport_5frouter_2eproto;
namespace transport_router_base {
class TransportRouter;
struct TransportRouterDefaultTypeInternal;
extern TransportRouterDefaultTypeInternal _TransportRouter_default_instance_;
class TransportRouterSettings;
struct TransportRouterSettingsDefaultTypeInternal;
extern TransportRouterSettingsDefaultTypeInternal _TransportRouterSettings_default_instance_;
}  // namespace transport_router_base
PROTOBUF_NAMESPACE_OPEN
template<> ::transport_router_base::TransportRouter* Arena::CreateMaybeMessage<::transport_router_base::TransportRouter>(Arena*);
template<> ::transport_router_base::TransportRouterSettings* Arena::CreateMaybeMessage<::transport_router_base::TransportRouterSettings>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace transport_router_base {

// ===================================================================

class TransportRouterSettings final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transport_router_base.TransportRouterSettings) */ {
 public:
  inline TransportRouterSettings() : TransportRouterSettings(nullptr) {}
  ~TransportRouterSettings() override;
  explicit PROTOBUF_CONSTEXPR TransportRouterSettings(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TransportRouterSettings(const TransportRouterSettings& from);
  TransportRouterSettings(TransportRouterSettings&& from) noexcept
    : TransportRouterSettings() {
    *this = ::std::move(from);
  }

  inline TransportRouterSettings& operator=(const TransportRouterSettings& from) {
    CopyFrom(from);
    return *this;
  }
  inline TransportRouterSettings& operator=(TransportRouterSettings&& from) noexcept {
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
  static const TransportRouterSettings& default_instance() {
    return *internal_default_instance();
  }
  static inline const TransportRouterSettings* internal_default_instance() {
    return reinterpret_cast<const TransportRouterSettings*>(
               &_TransportRouterSettings_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TransportRouterSettings& a, TransportRouterSettings& b) {
    a.Swap(&b);
  }
  inline void Swap(TransportRouterSettings* other) {
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
  void UnsafeArenaSwap(TransportRouterSettings* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TransportRouterSettings* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TransportRouterSettings>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TransportRouterSettings& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TransportRouterSettings& from);
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
  void InternalSwap(TransportRouterSettings* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transport_router_base.TransportRouterSettings";
  }
  protected:
  explicit TransportRouterSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBusWaitTimeFieldNumber = 1,
    kBusVelocityFieldNumber = 2,
  };
  // double bus_wait_time = 1;
  void clear_bus_wait_time();
  double bus_wait_time() const;
  void set_bus_wait_time(double value);
  private:
  double _internal_bus_wait_time() const;
  void _internal_set_bus_wait_time(double value);
  public:

  // double bus_velocity = 2;
  void clear_bus_velocity();
  double bus_velocity() const;
  void set_bus_velocity(double value);
  private:
  double _internal_bus_velocity() const;
  void _internal_set_bus_velocity(double value);
  public:

  // @@protoc_insertion_point(class_scope:transport_router_base.TransportRouterSettings)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double bus_wait_time_;
  double bus_velocity_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transport_5frouter_2eproto;
};
// -------------------------------------------------------------------

class TransportRouter final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transport_router_base.TransportRouter) */ {
 public:
  inline TransportRouter() : TransportRouter(nullptr) {}
  ~TransportRouter() override;
  explicit PROTOBUF_CONSTEXPR TransportRouter(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TransportRouter(const TransportRouter& from);
  TransportRouter(TransportRouter&& from) noexcept
    : TransportRouter() {
    *this = ::std::move(from);
  }

  inline TransportRouter& operator=(const TransportRouter& from) {
    CopyFrom(from);
    return *this;
  }
  inline TransportRouter& operator=(TransportRouter&& from) noexcept {
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
  static const TransportRouter& default_instance() {
    return *internal_default_instance();
  }
  static inline const TransportRouter* internal_default_instance() {
    return reinterpret_cast<const TransportRouter*>(
               &_TransportRouter_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TransportRouter& a, TransportRouter& b) {
    a.Swap(&b);
  }
  inline void Swap(TransportRouter* other) {
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
  void UnsafeArenaSwap(TransportRouter* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TransportRouter* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TransportRouter>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TransportRouter& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TransportRouter& from);
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
  void InternalSwap(TransportRouter* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "transport_router_base.TransportRouter";
  }
  protected:
  explicit TransportRouter(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSettingsFieldNumber = 1,
    kGraphFieldNumber = 2,
  };
  // .transport_router_base.TransportRouterSettings settings = 1;
  bool has_settings() const;
  private:
  bool _internal_has_settings() const;
  public:
  void clear_settings();
  const ::transport_router_base::TransportRouterSettings& settings() const;
  PROTOBUF_NODISCARD ::transport_router_base::TransportRouterSettings* release_settings();
  ::transport_router_base::TransportRouterSettings* mutable_settings();
  void set_allocated_settings(::transport_router_base::TransportRouterSettings* settings);
  private:
  const ::transport_router_base::TransportRouterSettings& _internal_settings() const;
  ::transport_router_base::TransportRouterSettings* _internal_mutable_settings();
  public:
  void unsafe_arena_set_allocated_settings(
      ::transport_router_base::TransportRouterSettings* settings);
  ::transport_router_base::TransportRouterSettings* unsafe_arena_release_settings();

  // .proto_graph.Graph graph = 2;
  bool has_graph() const;
  private:
  bool _internal_has_graph() const;
  public:
  void clear_graph();
  const ::proto_graph::Graph& graph() const;
  PROTOBUF_NODISCARD ::proto_graph::Graph* release_graph();
  ::proto_graph::Graph* mutable_graph();
  void set_allocated_graph(::proto_graph::Graph* graph);
  private:
  const ::proto_graph::Graph& _internal_graph() const;
  ::proto_graph::Graph* _internal_mutable_graph();
  public:
  void unsafe_arena_set_allocated_graph(
      ::proto_graph::Graph* graph);
  ::proto_graph::Graph* unsafe_arena_release_graph();

  // @@protoc_insertion_point(class_scope:transport_router_base.TransportRouter)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::transport_router_base::TransportRouterSettings* settings_;
  ::proto_graph::Graph* graph_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_transport_5frouter_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TransportRouterSettings

// double bus_wait_time = 1;
inline void TransportRouterSettings::clear_bus_wait_time() {
  bus_wait_time_ = 0;
}
inline double TransportRouterSettings::_internal_bus_wait_time() const {
  return bus_wait_time_;
}
inline double TransportRouterSettings::bus_wait_time() const {
  // @@protoc_insertion_point(field_get:transport_router_base.TransportRouterSettings.bus_wait_time)
  return _internal_bus_wait_time();
}
inline void TransportRouterSettings::_internal_set_bus_wait_time(double value) {
  
  bus_wait_time_ = value;
}
inline void TransportRouterSettings::set_bus_wait_time(double value) {
  _internal_set_bus_wait_time(value);
  // @@protoc_insertion_point(field_set:transport_router_base.TransportRouterSettings.bus_wait_time)
}

// double bus_velocity = 2;
inline void TransportRouterSettings::clear_bus_velocity() {
  bus_velocity_ = 0;
}
inline double TransportRouterSettings::_internal_bus_velocity() const {
  return bus_velocity_;
}
inline double TransportRouterSettings::bus_velocity() const {
  // @@protoc_insertion_point(field_get:transport_router_base.TransportRouterSettings.bus_velocity)
  return _internal_bus_velocity();
}
inline void TransportRouterSettings::_internal_set_bus_velocity(double value) {
  
  bus_velocity_ = value;
}
inline void TransportRouterSettings::set_bus_velocity(double value) {
  _internal_set_bus_velocity(value);
  // @@protoc_insertion_point(field_set:transport_router_base.TransportRouterSettings.bus_velocity)
}

// -------------------------------------------------------------------

// TransportRouter

// .transport_router_base.TransportRouterSettings settings = 1;
inline bool TransportRouter::_internal_has_settings() const {
  return this != internal_default_instance() && settings_ != nullptr;
}
inline bool TransportRouter::has_settings() const {
  return _internal_has_settings();
}
inline void TransportRouter::clear_settings() {
  if (GetArenaForAllocation() == nullptr && settings_ != nullptr) {
    delete settings_;
  }
  settings_ = nullptr;
}
inline const ::transport_router_base::TransportRouterSettings& TransportRouter::_internal_settings() const {
  const ::transport_router_base::TransportRouterSettings* p = settings_;
  return p != nullptr ? *p : reinterpret_cast<const ::transport_router_base::TransportRouterSettings&>(
      ::transport_router_base::_TransportRouterSettings_default_instance_);
}
inline const ::transport_router_base::TransportRouterSettings& TransportRouter::settings() const {
  // @@protoc_insertion_point(field_get:transport_router_base.TransportRouter.settings)
  return _internal_settings();
}
inline void TransportRouter::unsafe_arena_set_allocated_settings(
    ::transport_router_base::TransportRouterSettings* settings) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(settings_);
  }
  settings_ = settings;
  if (settings) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:transport_router_base.TransportRouter.settings)
}
inline ::transport_router_base::TransportRouterSettings* TransportRouter::release_settings() {
  
  ::transport_router_base::TransportRouterSettings* temp = settings_;
  settings_ = nullptr;
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
inline ::transport_router_base::TransportRouterSettings* TransportRouter::unsafe_arena_release_settings() {
  // @@protoc_insertion_point(field_release:transport_router_base.TransportRouter.settings)
  
  ::transport_router_base::TransportRouterSettings* temp = settings_;
  settings_ = nullptr;
  return temp;
}
inline ::transport_router_base::TransportRouterSettings* TransportRouter::_internal_mutable_settings() {
  
  if (settings_ == nullptr) {
    auto* p = CreateMaybeMessage<::transport_router_base::TransportRouterSettings>(GetArenaForAllocation());
    settings_ = p;
  }
  return settings_;
}
inline ::transport_router_base::TransportRouterSettings* TransportRouter::mutable_settings() {
  ::transport_router_base::TransportRouterSettings* _msg = _internal_mutable_settings();
  // @@protoc_insertion_point(field_mutable:transport_router_base.TransportRouter.settings)
  return _msg;
}
inline void TransportRouter::set_allocated_settings(::transport_router_base::TransportRouterSettings* settings) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete settings_;
  }
  if (settings) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(settings);
    if (message_arena != submessage_arena) {
      settings = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, settings, submessage_arena);
    }
    
  } else {
    
  }
  settings_ = settings;
  // @@protoc_insertion_point(field_set_allocated:transport_router_base.TransportRouter.settings)
}

// .proto_graph.Graph graph = 2;
inline bool TransportRouter::_internal_has_graph() const {
  return this != internal_default_instance() && graph_ != nullptr;
}
inline bool TransportRouter::has_graph() const {
  return _internal_has_graph();
}
inline const ::proto_graph::Graph& TransportRouter::_internal_graph() const {
  const ::proto_graph::Graph* p = graph_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto_graph::Graph&>(
      ::proto_graph::_Graph_default_instance_);
}
inline const ::proto_graph::Graph& TransportRouter::graph() const {
  // @@protoc_insertion_point(field_get:transport_router_base.TransportRouter.graph)
  return _internal_graph();
}
inline void TransportRouter::unsafe_arena_set_allocated_graph(
    ::proto_graph::Graph* graph) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(graph_);
  }
  graph_ = graph;
  if (graph) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:transport_router_base.TransportRouter.graph)
}
inline ::proto_graph::Graph* TransportRouter::release_graph() {
  
  ::proto_graph::Graph* temp = graph_;
  graph_ = nullptr;
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
inline ::proto_graph::Graph* TransportRouter::unsafe_arena_release_graph() {
  // @@protoc_insertion_point(field_release:transport_router_base.TransportRouter.graph)
  
  ::proto_graph::Graph* temp = graph_;
  graph_ = nullptr;
  return temp;
}
inline ::proto_graph::Graph* TransportRouter::_internal_mutable_graph() {
  
  if (graph_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto_graph::Graph>(GetArenaForAllocation());
    graph_ = p;
  }
  return graph_;
}
inline ::proto_graph::Graph* TransportRouter::mutable_graph() {
  ::proto_graph::Graph* _msg = _internal_mutable_graph();
  // @@protoc_insertion_point(field_mutable:transport_router_base.TransportRouter.graph)
  return _msg;
}
inline void TransportRouter::set_allocated_graph(::proto_graph::Graph* graph) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(graph_);
  }
  if (graph) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(graph));
    if (message_arena != submessage_arena) {
      graph = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, graph, submessage_arena);
    }
    
  } else {
    
  }
  graph_ = graph;
  // @@protoc_insertion_point(field_set_allocated:transport_router_base.TransportRouter.graph)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace transport_router_base

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_transport_5frouter_2eproto
