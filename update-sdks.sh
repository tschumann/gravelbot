#!/bin/bash

set -eu

cd $(dirname "${BASH_SOURCE[0]}")

for game in "bms" "dods" "insurgency" "hl2dm" "sdk2013"; do
	pushd ./$game/hl2sdk > /dev/null

	if [ $game = "insurgency" ]; then
		git checkout episode1
	else
		git checkout $game
	fi

	popd > /dev/null
done
 