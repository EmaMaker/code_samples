<?php


/*
 *  THIS CODE SLOWS DOWN THE BROWSER, CALCULATING THE MD5 HASH OF THE
 *  MILLISECONDS OF THE THE CURRENT SECONDS AND PRINTING THEM IN VARIABLE-LENGTH LINES
 *  ONYL TESTED ON LOCAL MACHINE: I DON'T WHAT HAPPENS IF EXECUTED FROM A REMOTE HOST
 */

header('Content-type: text/plain');


for ($i = 0; $i < 20; $i++) {

    for ($j = 0; j < random_int(10, 15); $j++) {
        $rand = substr(md5(microtime()), 0, random_int(25, 50));
        print $rand . " ";
    }


    print "\n";

}

?>
