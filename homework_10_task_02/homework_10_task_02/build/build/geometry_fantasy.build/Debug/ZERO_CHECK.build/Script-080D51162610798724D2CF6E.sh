#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build
  make -f /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build
  make -f /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build
  make -f /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build
  make -f /Users/tkvitko/c/netology/xcode_projects/homework_10_task_02/homework_10_task_02/build/CMakeScripts/ReRunCMake.make
fi

