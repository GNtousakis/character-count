#include <nan.h>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

NAN_METHOD(CharacterCount) {
  Isolate* isolate = info.GetIsolate();
  
  // Check the number of arguments passed.
  if (info.Length() == 0 || !info[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  String::Utf8Value tmp(info[0]->ToString());
  String::Utf8Value tmp2(info[1]->ToString());
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

  info.GetReturnValue().Set(counter);
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT(target, CharacterCount);
}

NODE_MODULE(CharacterCount, Init)
