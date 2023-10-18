clear
printf "\n"
echo "3 => max 3"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq 3 | shuf | paste -s -d ' ')
    ./push_swap $ARGS | wc -l | tr '\n' ' ';
    echo -n "|";
    ./push_swap $ARGS | ./checker_linux $ARGS;
done
printf "\n"
echo "3 => max 3 - negatives"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq -3 0 | shuf | paste -s -d ' ')
    ./push_swap $ARGS | wc -l | tr '\n' ' '
    echo -n "| "
    ./push_swap $ARGS | ./checker_linux $ARGS
done
printf "\n"
echo "100 => max 700"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq 100 | shuf | paste -s -d ' ')
    ./push_swap $ARGS | wc -l | tr '\n' ' '
    echo -n "| "
    ./push_swap $ARGS | ./checker_linux $ARGS
done
printf "\n"
echo "100 => max 700 - negatives"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq -100 0 | shuf | paste -s -d ' ');
    ./push_swap $ARGS | wc -l | tr '\n' ' '
    echo -n "| "
    ./push_swap $ARGS | ./checker_linux $ARGS
done
printf "\n"
echo "500 => max 5500"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq 500 | shuf | paste -s -d ' ');
    ./push_swap $ARGS | wc -l | tr '\n' ' '
    echo -n "| "
    ./push_swap $ARGS | ./checker_linux $ARGS
done
printf "\n"
echo "500 => max 5500 - negatives"
echo "==="
count=50
for i in $(seq $count); do
    ARGS=$(seq -500 0 | shuf | paste -s -d ' ')
    ./push_swap $ARGS | wc -l | tr '\n' ' '
    echo -n "| "
    ./push_swap $ARGS | ./checker_linux $ARGS
done

printf "\n"
