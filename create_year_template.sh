#!/bin/bash

year=$1

if [ -z "$year" ]; then
  echo "Usage: $0 <year>"
  exit 1
fi

year_dir="$year"
template_dir="day_template"

# Check if the year directory exists
if [ ! -d "$year_dir" ]; then
  # If it doesn't exist, create it and copy the day_template 25 times
  mkdir -p "$year_dir"
  for day in {1..25}; do
    day_dir="$year_dir/day_$(printf "%02d" $day)"
    mkdir -p "$day_dir"
    cp "$template_dir"/* "$day_dir"
  done
  echo "Created directory for $year and copied day_template for all 25 days."
else
  # If it exists, only copy the day_template for the days not already present
  for day in {1..25}; do
    day_dir="$year_dir/day_$(printf "%02d" $day)"
    if [ ! -d "$day_dir" ]; then
      mkdir -p "$day_dir"
      cp "$template_dir"/* "$day_dir"
    fi
  done
  echo "Year $year directory already exists. Copied missing day_template directories."
fi
