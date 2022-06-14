// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_graph_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_graph_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_graph_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_graph_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_graph_2eproto;
namespace proto_graph {
class Edge;
struct EdgeDefaultTypeInternal;
extern EdgeDefaultTypeInternal _Edge_default_instance_;
class Graph;
struct GraphDefaultTypeInternal;
extern GraphDefaultTypeInternal _Graph_default_instance_;
}  // namespace proto_graph
PROTOBUF_NAMESPACE_OPEN
template<> ::proto_graph::Edge* Arena::CreateMaybeMessage<::proto_graph::Edge>(Arena*);
template<> ::proto_graph::Graph* Arena::CreateMaybeMessage<::proto_graph::Graph>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto_graph {

// ===================================================================

class Edge final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_graph.Edge) */ {
 public:
  inline Edge() : Edge(nullptr) {}
  ~Edge() override;
  explicit PROTOBUF_CONSTEXPR Edge(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Edge(const Edge& from);
  Edge(Edge&& from) noexcept
    : Edge() {
    *this = ::std::move(from);
  }

  inline Edge& operator=(const Edge& from) {
    CopyFrom(from);
    return *this;
  }
  inline Edge& operator=(Edge&& from) noexcept {
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
  static const Edge& default_instance() {
    return *internal_default_instance();
  }
  static inline const Edge* internal_default_instance() {
    return reinterpret_cast<const Edge*>(
               &_Edge_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Edge& a, Edge& b) {
    a.Swap(&b);
  }
  inline void Swap(Edge* other) {
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
  void UnsafeArenaSwap(Edge* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Edge* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Edge>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Edge& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Edge& from);
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
  void InternalSwap(Edge* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_graph.Edge";
  }
  protected:
  explicit Edge(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFromIdFieldNumber = 1,
    kToIdFieldNumber = 2,
    kWeightFieldNumber = 3,
    kSpanCountFieldNumber = 4,
    kBusIdFieldNumber = 5,
  };
  // uint32 from_id = 1;
  void clear_from_id();
  uint32_t from_id() const;
  void set_from_id(uint32_t value);
  private:
  uint32_t _internal_from_id() const;
  void _internal_set_from_id(uint32_t value);
  public:

  // uint32 to_id = 2;
  void clear_to_id();
  uint32_t to_id() const;
  void set_to_id(uint32_t value);
  private:
  uint32_t _internal_to_id() const;
  void _internal_set_to_id(uint32_t value);
  public:

  // double weight = 3;
  void clear_weight();
  double weight() const;
  void set_weight(double value);
  private:
  double _internal_weight() const;
  void _internal_set_weight(double value);
  public:

  // uint32 span_count = 4;
  void clear_span_count();
  uint32_t span_count() const;
  void set_span_count(uint32_t value);
  private:
  uint32_t _internal_span_count() const;
  void _internal_set_span_count(uint32_t value);
  public:

  // uint32 bus_id = 5;
  void clear_bus_id();
  uint32_t bus_id() const;
  void set_bus_id(uint32_t value);
  private:
  uint32_t _internal_bus_id() const;
  void _internal_set_bus_id(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto_graph.Edge)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  uint32_t from_id_;
  uint32_t to_id_;
  double weight_;
  uint32_t span_count_;
  uint32_t bus_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// -------------------------------------------------------------------

class Graph final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto_graph.Graph) */ {
 public:
  inline Graph() : Graph(nullptr) {}
  ~Graph() override;
  explicit PROTOBUF_CONSTEXPR Graph(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Graph(const Graph& from);
  Graph(Graph&& from) noexcept
    : Graph() {
    *this = ::std::move(from);
  }

  inline Graph& operator=(const Graph& from) {
    CopyFrom(from);
    return *this;
  }
  inline Graph& operator=(Graph&& from) noexcept {
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
  static const Graph& default_instance() {
    return *internal_default_instance();
  }
  static inline const Graph* internal_default_instance() {
    return reinterpret_cast<const Graph*>(
               &_Graph_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Graph& a, Graph& b) {
    a.Swap(&b);
  }
  inline void Swap(Graph* other) {
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
  void UnsafeArenaSwap(Graph* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Graph* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Graph>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Graph& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Graph& from);
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
  void InternalSwap(Graph* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto_graph.Graph";
  }
  protected:
  explicit Graph(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEdgesFieldNumber = 1,
    kVertexCountFieldNumber = 2,
  };
  // repeated .proto_graph.Edge edges = 1;
  int edges_size() const;
  private:
  int _internal_edges_size() const;
  public:
  void clear_edges();
  ::proto_graph::Edge* mutable_edges(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_graph::Edge >*
      mutable_edges();
  private:
  const ::proto_graph::Edge& _internal_edges(int index) const;
  ::proto_graph::Edge* _internal_add_edges();
  public:
  const ::proto_graph::Edge& edges(int index) const;
  ::proto_graph::Edge* add_edges();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_graph::Edge >&
      edges() const;

  // uint32 vertex_count = 2;
  void clear_vertex_count();
  uint32_t vertex_count() const;
  void set_vertex_count(uint32_t value);
  private:
  uint32_t _internal_vertex_count() const;
  void _internal_set_vertex_count(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto_graph.Graph)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_graph::Edge > edges_;
  uint32_t vertex_count_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Edge

// uint32 from_id = 1;
inline void Edge::clear_from_id() {
  from_id_ = 0u;
}
inline uint32_t Edge::_internal_from_id() const {
  return from_id_;
}
inline uint32_t Edge::from_id() const {
  // @@protoc_insertion_point(field_get:proto_graph.Edge.from_id)
  return _internal_from_id();
}
inline void Edge::_internal_set_from_id(uint32_t value) {
  
  from_id_ = value;
}
inline void Edge::set_from_id(uint32_t value) {
  _internal_set_from_id(value);
  // @@protoc_insertion_point(field_set:proto_graph.Edge.from_id)
}

// uint32 to_id = 2;
inline void Edge::clear_to_id() {
  to_id_ = 0u;
}
inline uint32_t Edge::_internal_to_id() const {
  return to_id_;
}
inline uint32_t Edge::to_id() const {
  // @@protoc_insertion_point(field_get:proto_graph.Edge.to_id)
  return _internal_to_id();
}
inline void Edge::_internal_set_to_id(uint32_t value) {
  
  to_id_ = value;
}
inline void Edge::set_to_id(uint32_t value) {
  _internal_set_to_id(value);
  // @@protoc_insertion_point(field_set:proto_graph.Edge.to_id)
}

// double weight = 3;
inline void Edge::clear_weight() {
  weight_ = 0;
}
inline double Edge::_internal_weight() const {
  return weight_;
}
inline double Edge::weight() const {
  // @@protoc_insertion_point(field_get:proto_graph.Edge.weight)
  return _internal_weight();
}
inline void Edge::_internal_set_weight(double value) {
  
  weight_ = value;
}
inline void Edge::set_weight(double value) {
  _internal_set_weight(value);
  // @@protoc_insertion_point(field_set:proto_graph.Edge.weight)
}

// uint32 span_count = 4;
inline void Edge::clear_span_count() {
  span_count_ = 0u;
}
inline uint32_t Edge::_internal_span_count() const {
  return span_count_;
}
inline uint32_t Edge::span_count() const {
  // @@protoc_insertion_point(field_get:proto_graph.Edge.span_count)
  return _internal_span_count();
}
inline void Edge::_internal_set_span_count(uint32_t value) {
  
  span_count_ = value;
}
inline void Edge::set_span_count(uint32_t value) {
  _internal_set_span_count(value);
  // @@protoc_insertion_point(field_set:proto_graph.Edge.span_count)
}

// uint32 bus_id = 5;
inline void Edge::clear_bus_id() {
  bus_id_ = 0u;
}
inline uint32_t Edge::_internal_bus_id() const {
  return bus_id_;
}
inline uint32_t Edge::bus_id() const {
  // @@protoc_insertion_point(field_get:proto_graph.Edge.bus_id)
  return _internal_bus_id();
}
inline void Edge::_internal_set_bus_id(uint32_t value) {
  
  bus_id_ = value;
}
inline void Edge::set_bus_id(uint32_t value) {
  _internal_set_bus_id(value);
  // @@protoc_insertion_point(field_set:proto_graph.Edge.bus_id)
}

// -------------------------------------------------------------------

// Graph

// repeated .proto_graph.Edge edges = 1;
inline int Graph::_internal_edges_size() const {
  return edges_.size();
}
inline int Graph::edges_size() const {
  return _internal_edges_size();
}
inline void Graph::clear_edges() {
  edges_.Clear();
}
inline ::proto_graph::Edge* Graph::mutable_edges(int index) {
  // @@protoc_insertion_point(field_mutable:proto_graph.Graph.edges)
  return edges_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_graph::Edge >*
Graph::mutable_edges() {
  // @@protoc_insertion_point(field_mutable_list:proto_graph.Graph.edges)
  return &edges_;
}
inline const ::proto_graph::Edge& Graph::_internal_edges(int index) const {
  return edges_.Get(index);
}
inline const ::proto_graph::Edge& Graph::edges(int index) const {
  // @@protoc_insertion_point(field_get:proto_graph.Graph.edges)
  return _internal_edges(index);
}
inline ::proto_graph::Edge* Graph::_internal_add_edges() {
  return edges_.Add();
}
inline ::proto_graph::Edge* Graph::add_edges() {
  ::proto_graph::Edge* _add = _internal_add_edges();
  // @@protoc_insertion_point(field_add:proto_graph.Graph.edges)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto_graph::Edge >&
Graph::edges() const {
  // @@protoc_insertion_point(field_list:proto_graph.Graph.edges)
  return edges_;
}

// uint32 vertex_count = 2;
inline void Graph::clear_vertex_count() {
  vertex_count_ = 0u;
}
inline uint32_t Graph::_internal_vertex_count() const {
  return vertex_count_;
}
inline uint32_t Graph::vertex_count() const {
  // @@protoc_insertion_point(field_get:proto_graph.Graph.vertex_count)
  return _internal_vertex_count();
}
inline void Graph::_internal_set_vertex_count(uint32_t value) {
  
  vertex_count_ = value;
}
inline void Graph::set_vertex_count(uint32_t value) {
  _internal_set_vertex_count(value);
  // @@protoc_insertion_point(field_set:proto_graph.Graph.vertex_count)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_graph

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_graph_2eproto
