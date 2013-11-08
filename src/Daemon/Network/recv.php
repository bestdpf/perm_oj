<?php
if (move_uploaded_file($_FILES["sendfile"]["tmp_name"], $_FILES["sendfile"]["name"])) {
    echo "File is valid, and was successfully uploaded.\n";
} else {
    echo "Possible file upload attack!\n";
}
?>
