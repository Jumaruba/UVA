#!/usr/bin/env fish

# The # must be replaced by a number such as 1,2,3,...
# TODO: change show diff and test, test a specific test and show help
#TODo: show execution time

set IN ./testdata/*.in
set OUT ./testdata/*.out
set TESTS (count $IN)
set SHOW_DIFF true

# Compiling option
set CPP g++ -O2 -w -lm # C++

function compile -a SOURCE
    echo "================COMPILE================"
    $CPP $SOURCE
    set_color blue 
    echo "[COMPILE] 💨 Starting..."
    set_color green
    echo "[COMPILE] ⭕ $SOURCE compiled!"
    set_color normal
end 


function execute 
    echo "=================TESTS================="
    for i in (seq 1 $TESTS)
        ./a.out < ./testdata/$i.in > ./testdata/$i.myout
        set result (diff ./testdata/$i.out ./testdata/$i.myout)
        show_result "$result" $i
    end 
end


function show_result -a result testnum 
    if test -z "$result" 
        set_color green    
        echo "[TEST::$testnum] :: ✔️ PASSED!"
    else if $SHOW_DIFF
        set_color red 
        echo "[TEST::$testnum] :: ❌ WRONG ANSWER!"
        set_color normal
        diff -c ./testdata/$testnum.out ./testdata/$testnum.myout
    else 
        set_color red 
        echo "[TEST::$testnum] :: ❌ WRONG ANSWER!"
    end 
    set_color normal
end 


# MAIN ==================================================================
if test (count $argv) -lt 1
  echo "ℹ️ Usage: ./test <source-code>"
else if not test -d "./testdata"
    echo "⛔ Missing testdata folder! Create one!"
else if test (count $IN) -ne (count $OUT)
    echo "⛔ Number of outputs must be equal to the number of inputs"
else 
    compile $argv[1]
    execute
end

