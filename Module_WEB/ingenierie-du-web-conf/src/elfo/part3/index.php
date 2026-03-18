<?php
header('Content-Type: application/json');

// On pourrait gérer directement le problème depuis Apache/PHP ainsi :
// (mais ça n'est pas le but ici)
// header('Access-Control-Allow-Origin: http://bean.localhost');

$message = [
    'message' => 'Yes, ça fonctionne !',
    'time' => date('Y-m-d H:i:s'),
    'ip' => $_SERVER['REMOTE_ADDR'],
    'user_agent' => $_SERVER['HTTP_USER_AGENT']
];

echo json_encode($message);
