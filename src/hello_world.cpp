// Copyright (c) Database Group, Nagoya University. All rights reserved.
// Licensed under the MIT license.

#include "gflags/gflags.h"

// set command line options
DEFINE_bool(test, false, "test");

int
main(int argc, char* argv[])
{
  // parse and remove command line options
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  return 0;
}
