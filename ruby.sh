ARG="`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`"; ./push_swap $ARG | ./checker $ARG
