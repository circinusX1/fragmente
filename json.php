<?php

//
//  A php sample which takes the post content and decript it using private certificate
//

//	$rkey = file_get_contents("/var/www/html/privkey.pem");
//	$pkey = file_get_contents("/var/www/html/newcert.pem");
	$data = file_get_contents("php://input");
	$fenc = tempnam("", "enc");
	$fdec = tempnam("", "dec");
	file_put_contents($fenc,$data);
//	openssl_pkcs7_decrypt ($fenc , $fdec , $pkey, $rkey );
	system("openssl smime -decrypt -in ${fenc} -inform DER -inkey privkey.pem -out ${fdec}");
	echo  file_get_contents($fdec);
?>
