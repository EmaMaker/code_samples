<?php

/*
 * RANDOM WEB PAGE GENERATOR, WITH RANDOM TEXT AND SINGLE IMAGE
 */

//first of all makes all the things for the image and sames it into $re
$url = 'http://www.google.com/doodle4google/images/d4g_logo_global.jpg';
$allow = ['gif', 'jpg', 'png'];  // allowed extensions
$img = file_get_contents($url);
$url_info = pathinfo($url);

// if allowed extension
if (in_array($url_info['extension'], $allow)) {
    // Format the image SRC:  data:{mime};base64,{img_data_base64};
    $src = 'data:image/' . $url_info['extension'] . ';base64,' . base64_encode($img);

    // add the base64 image into a <img> to display it
    $re = '<img src="' . $src . '" alt="' . $url_info['basename'] . '"style="width:406px;height:109px;" />';
} else $re = 'Invalid extension: ' . $url_info['extension'];

$chars = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM<>,;.:-_ÒÀÙÈ+Ç°§É*òàùè+{}#[]@1234567890'ì?^\|!£$%&/()=?^\"";

for ($i = 0; $i < random_int(40, 50); $i++) {
    $word = "";
    for ($j = 0; $j < random_int(1,4); $j++) {

        $word .= substr($chars, random_int(0,strlen($chars) / 2), random_int(strlen($chars) / 2, strlen($chars)));
    }
    echo "<pre>\n" . $word . "</pre>";

    if (random_int(0, 10) <= 1) {
        echo "<pre>\n" . $re . "</pre>";
    }
}


?>
