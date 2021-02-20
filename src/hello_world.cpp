// Copyright (c) Database Group, Nagoya University. All rights reserved.
// Licensed under the MIT license.

#include "gflags/gflags.h"
#include "glog/logging.h"

// set command line options
DEFINE_bool(test, false, "test");

int
main(int argc, char* argv[])
{
  // init glog with a program name
  google::InitGoogleLogging(argv[0]);

  // parse and remove command line options
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // `LOG` macro always outputs messages
  LOG(INFO) << "Hello, world!";

  // `DLOG` macro will be excluded in Release build
  DLOG(INFO) << "Hello, debug world!";

  // set options can be accessed with `FLAGS_` prefix
  if (FLAGS_test) {
    LOG(INFO) << "This message is shown only if '--test' option is specified.";
  }

  return 0;
}
