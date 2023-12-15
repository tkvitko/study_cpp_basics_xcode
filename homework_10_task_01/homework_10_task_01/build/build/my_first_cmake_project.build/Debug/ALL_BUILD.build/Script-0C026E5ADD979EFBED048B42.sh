#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_01/homework_10_task_01/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_01/homework_10_task_01/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_01/homework_10_task_01/build
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/tkvitko/c/netology/xcode_projects/homework_10_task_01/homework_10_task_01/build
  echo Build\ all\ projects
fi

