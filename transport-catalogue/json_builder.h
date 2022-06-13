#pragma once

#include "json.h"

#include <exception>
#include <memory>

namespace json {

enum class Command {
    CONSTRUCTOR,
    VALUE,
    START_DICT,
    END_DICT,
    START_ARRAY,
    END_ARRAY,
    KEY
};

class Builder {
private:
    std::string dict_key_;
    Dict raw_dict_;
    Array raw_array_;
    Node raw_data_;
    bool is_dict_opened_ = false;
    bool is_array_opened_ = false;
    bool is_ready_ = false;
    Command last_command_;
    std::unique_ptr<Builder> child_builder_;
    Builder* parent_builder_ = nullptr;
    
    Builder& ReleaseChild();
    
    class BuilderWrapperKey;
    class BuilderWrapperKeyValue;
    class BuilderWrapperArray;
    class BuilderWrapperDict;
    class BuilderWrapperArrayValue;
    
    class BuilderWrapper {
    public:
        BuilderWrapper(Builder& b);
    
        BuilderWrapperKey Key(std::string key);
        BuilderWrapperArray StartArray();
        BuilderWrapperDict StartDict();
        Builder& EndDict();
        Builder& EndArray();
        Node Build();
    
        Builder& GetBuilder();
    private:
        Builder& builder_;
    };
    
    class BuilderWrapperKey : public BuilderWrapper {
    public:
        BuilderWrapperKey(Builder& b);
                
        BuilderWrapperKeyValue Value(Node node);
        BuilderWrapperKey Key(std::string key) = delete;
        Builder& EndDict() = delete;
        Builder& EndArray() = delete;
        Node Build() = delete;
    };

    class BuilderWrapperKeyValue : public BuilderWrapper {
    public:
        BuilderWrapperKeyValue(Builder& b);
        
        BuilderWrapperArray StartArray() = delete;
        BuilderWrapperDict StartDict() = delete;
        Builder& EndArray() = delete;
        Node Build() = delete;
    };
    
    class BuilderWrapperArray : public BuilderWrapper {
    public:
        BuilderWrapperArray(Builder& b);
        
        BuilderWrapperArrayValue Value(Node node);
        BuilderWrapperKey Key(std::string key) = delete;
        Builder& EndDict() = delete;
        Node Build() = delete;
    };
    
    class BuilderWrapperArrayValue : public BuilderWrapper {
    public:
        BuilderWrapperArrayValue(Builder& b);
        
        BuilderWrapperArrayValue Value(Node node);
        BuilderWrapperKey Key(std::string key) = delete;
        Builder& EndDict() = delete;
        Node Build() = delete;
    };
    
    class BuilderWrapperDict : public BuilderWrapper {
    public:
        BuilderWrapperDict(Builder& b);
        
        BuilderWrapperArray StartArray() = delete;
        BuilderWrapperDict StartDict() = delete;
        Builder& EndArray() = delete;
        Node Build() = delete;
    };
    
    class BuilderWrapperValue : public BuilderWrapper {
    public:
        BuilderWrapperValue(Builder& b);
        
        BuilderWrapperKey Key(std::string key) = delete;
        BuilderWrapperArray StartArray() = delete;
        BuilderWrapperDict StartDict() = delete;
        Builder& EndDict() = delete;
        Builder& EndArray() = delete;
    };
    
public:
    Builder() = default;
    Builder(Builder* parent);
    
    Node Build();
    Builder::BuilderWrapperDict StartDict();
    Builder& EndDict();
    BuilderWrapperArray StartArray();
    Builder& EndArray();
    BuilderWrapperKey Key(std::string);
    Builder& Value(Node);
};

} //namespace json
