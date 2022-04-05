#!/bin/bash
repo=.

function check_file_in_folder()
{
  for file in "$1"/*
  do
    if [ -f "$file" ]; then
      ext="${file##*.}"
      if [[ $ext != c ]] && [[ $ext != h ]] && [[ $file != *Makefile ]]; then
        echo 1
      fi
    fi
    if [ -d "$file" ]; then
      if [[ $file != bonus ]] && [[ $file != assets ]]; then
        check_file_in_folder $file
      fi
    fi
  done
}

check_file_in_folder $repo

