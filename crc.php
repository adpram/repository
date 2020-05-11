<?php
    $input = readline("Input : ");
    echo "Output : " .  hash('crc32b', $input) ;
?>