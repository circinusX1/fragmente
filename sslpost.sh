#!/bin/bash
#
# posts json.xxx encoded file to json.php
#

curl --request POST --data-binary @./json.xxx http://localhost/json.php

