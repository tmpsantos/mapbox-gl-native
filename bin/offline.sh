#!/usr/bin/env bash

set -e
set -o pipefail

OFFLINE=./build/linux-x86_64/Release/mbgl-offline

# Barcelona
$OFFLINE --north 41.4664 --west 2.0407 --south 41.2724 --east 2.2680 --output barcelona.db
