#include <nan.h>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

void CharacterCount(const FunctionCallbackInfo<Value>& args){
  Isolate* isolate = args.GetIsolate();
  
  // Check the number of arguments passed.
  if (args.Length() == 0 || !args[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  String::Utf8Value tmp(args[0]->ToString());
  String::Utf8Value tmp2(args[1]->ToString());
  int counter = 0;
  // Change string to c++ type
  std::string str = std::string(*tmp); 
  std::string character = std::string(*tmp2);
  int len = str.length();
  for (int i = 0; i <= len; i++) {
    if (str[i] == character[0]) {
      counter++;
    }
  }

  args.GetReturnValue().Set(counter);
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "CharacterCount", CharacterCount);
}

NODE_MODULE(CharacterCount, Init)
