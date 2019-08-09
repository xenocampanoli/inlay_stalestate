#!/usr/bin/enb bats

@test "Basic usage statement works." {
    result="$(./bake.py -h)"
    [[ -n $result ]]
}
