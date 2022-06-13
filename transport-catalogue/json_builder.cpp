#include "json_builder.h"

namespace json {

using namespace std::literals;

//BuilderWrapper

Builder::BuilderWrapper::BuilderWrapper(Builder& b) : builder_(b) {}

Builder& Builder::BuilderWrapper::GetBuilder() {
    return builder_;
}

Builder::BuilderWrapperKey Builder::BuilderWrapper::Key(std::string key) {
    return {GetBuilder().Key(std::move(key))};
}

Builder::BuilderWrapperArray Builder::BuilderWrapper::StartArray() {
    return {GetBuilder().StartArray()};
}

Builder::BuilderWrapperDict Builder::BuilderWrapper::StartDict() {
    return {GetBuilder().StartDict()};
}

Builder& Builder::BuilderWrapper::EndArray() {
    return {GetBuilder().EndArray()};
}

Builder& Builder::BuilderWrapper::EndDict() {
    return {GetBuilder().EndDict()};
}

Node Builder::BuilderWrapper::Build() {
    return {GetBuilder().Build()};
}

//BuilderWrapperKey
Builder::BuilderWrapperKey::BuilderWrapperKey(Builder& b) : Builder::BuilderWrapper(b) {}

Builder::BuilderWrapperKeyValue Builder::BuilderWrapperKey::Value(Node node) {
    return {GetBuilder().Value(node)};
}

//BuilderWrapperKeyValue
Builder::BuilderWrapperKeyValue::BuilderWrapperKeyValue(Builder& b) : Builder::BuilderWrapper(b) {}

//BuilderWrapperArray
Builder::BuilderWrapperArray::BuilderWrapperArray(Builder& b) : Builder::BuilderWrapper(b) {}

Builder::BuilderWrapperArrayValue Builder::BuilderWrapperArray::Value(Node node) {
    return {GetBuilder().Value(node)};
}

//BuilderWrapperDict

Builder::BuilderWrapperDict::BuilderWrapperDict(Builder& b) : Builder::BuilderWrapper(b) {}

//BuilderWrapperArrayValue

Builder::BuilderWrapperArrayValue::BuilderWrapperArrayValue(Builder& b) : Builder::BuilderWrapper(b) {}

Builder::BuilderWrapperArrayValue Builder::BuilderWrapperArrayValue::Value(Node node) {
    return {GetBuilder().Value(node)};
}

//BuilderWrapperValue
Builder::BuilderWrapperValue::BuilderWrapperValue(Builder& b) : Builder::BuilderWrapper(b) {}

//Builder

Builder::Builder(Builder* parent) : parent_builder_(parent) {
    last_command_ = Command::CONSTRUCTOR;
}

Node Builder::Build() {
    if(!is_ready_) {
        throw std::logic_error("data is not ready"s);
    }
    if(last_command_ == Command::END_DICT) {
        return raw_dict_;
    }
    else if(last_command_ == Command::END_ARRAY) {
        return raw_array_;
    }
    else {
        return raw_data_;
    }
}

Builder::BuilderWrapperDict Builder::StartDict() {
    if(last_command_ == Command::KEY) {
        throw std::logic_error("unable to open dict after key"s);
    }
    if(is_ready_) {
        throw std::logic_error("unable to open dict after data complete"s);
    }
    if(is_dict_opened_) {
        throw std::logic_error("dict is already has been opened"s);
    }
    if(is_array_opened_) {
        if(child_builder_) {
            raw_array_.emplace_back(std::move(child_builder_->Build()));
            child_builder_.reset(nullptr);
        }
        child_builder_ = std::make_unique<Builder>(this);
        return {child_builder_->StartDict()};
    }
    is_dict_opened_ = true;
    last_command_ = Command::START_DICT;
    return {*this};
}

Builder::BuilderWrapperKey Builder::Key(std::string key) {
    if(!is_dict_opened_) {
        throw std::logic_error("unable to set key outside dict\n"s);
    }
    if(last_command_ == Command::KEY) {
        throw std::logic_error("unable to set key after another key\n"s);
    }
    if(child_builder_) {
        raw_dict_[dict_key_] = child_builder_->Build();
        dict_key_.clear();
        child_builder_.reset(nullptr);
    }
    dict_key_ = std::move(key);
    last_command_ = Command::KEY;
    child_builder_ = std::make_unique<Builder>(this);
    return {*child_builder_};
}

Builder& Builder::EndDict() {
    if(!is_dict_opened_) {
        throw std::logic_error("dict is not opened"s);
    }
    if(last_command_ == Command::KEY) {
        throw std::logic_error("unable to close dict after setting key"s);
    }
    if(is_ready_) {
        throw std::logic_error("unable to close dict after data complete"s);
    }
    if(child_builder_) {
        raw_dict_[dict_key_] = std::move(child_builder_->Build());
        dict_key_.clear();
        child_builder_.reset(nullptr);
    }
    is_dict_opened_ = false;
    is_ready_ = true;
    last_command_ = Command::END_DICT;
    if(parent_builder_) {
        parent_builder_->last_command_ = last_command_;
    }
    return parent_builder_ ? *parent_builder_ : *this;
}

Builder::BuilderWrapperArray Builder::StartArray() {
    if(last_command_ == Command::START_DICT) {
        throw std::logic_error("unable to start array after start_dict"s);
    }
    if(is_ready_) {
        throw std::logic_error("unable to start array after data complete"s);
    }
    if(is_array_opened_) {
        child_builder_ = std::make_unique<Builder>(this);
        return {child_builder_->StartArray()};
    }
    else {
        is_array_opened_ = true;
        last_command_ = Command::START_ARRAY;
        return {*this};
    }
}

Builder& Builder::Value(Node val) {
    if(last_command_ == Command::VALUE && !is_array_opened_) {
        throw std::logic_error("unable to set value after value"s);
    }
    if(is_ready_) {
        throw std::logic_error("unable to set value after data complete"s);
    }
    if(last_command_ == Command::START_DICT) {
        throw std::logic_error("unable to set value to dict with no key"s);
    }
    last_command_ = Command::VALUE;
    if(is_array_opened_) {
        if(child_builder_) {
            raw_array_.emplace_back(std::move(child_builder_->Build()));
            child_builder_.reset(nullptr);
        }
        raw_array_.emplace_back(std::move(val));
        return *this;
    }
    else {
        raw_data_ = std::move(val);
        is_ready_ = true;
        if(parent_builder_) {
            parent_builder_->last_command_ = last_command_;
        }
        return parent_builder_ ? *parent_builder_ : *this;
    }
}

Builder& Builder::EndArray() {
    if(!is_array_opened_) {
        throw std::logic_error("array is not opened"s);
    }
    if(is_ready_) {
        throw std::logic_error("unable to close array after data complete"s);
    }
    if(child_builder_) {
        raw_array_.emplace_back(std::move(child_builder_->Build()));
        child_builder_.reset(nullptr);
    }
    is_array_opened_ = false;
    is_ready_ = true;
    last_command_ = Command::END_ARRAY;
    if(parent_builder_) {
        parent_builder_->last_command_ = last_command_;
    }
    return parent_builder_ ? *parent_builder_ : *this;
}

Builder& Builder::ReleaseChild() {
    child_builder_.reset(nullptr);
    return *this;
}

} //namespace json
