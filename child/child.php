<?php
$server = "localhost";
$username = "root";
$password = "";
$db = "study";
$conn = new mysqli($server,$username,$password,$db);
if($conn -> connect_error){
   die("Connection failed: ".$conn->connect_error);
}

header('Content-Type: application/json');
$method = $_SERVER['REQUEST_METHOD'];
switch($method){
   case 'POST':
      $name = $_POST['Name'];
      $scl = $_POST['School'];
      $sql = "INSERT INTO child(Name,School) VALUES (?,?)";
      $stmt = $conn->prepare($sql);
      $stmt->bind_param('ss',$name,$scl);
      if($stmt -> execute()){
         echo json_encode(array('status' => 'success'));
      }
      else{
         http_response_code(500);
         echo json_encode(array('error'=>'Failed to record userdata.'));
      }

      break;
      case 'GET':
         $result = $conn->query("SELECT * FROM child ORDER BY Id DESC");
         $userdata = array();
         while($row = $result -> fetch_assoc()){ 
            $userdata[] = $row;
         }
         echo json_encode($userdata);
         break;
         case 'PUT':
            parse_str(file_get_contents("php://input"), $_PUT);
            $id = $_PUT['Id'];
            $name = $_PUT['Name'];
            $scl = $_PUT['School'];

            $sql = "UPDATE child SET Name=?, School=? WHERE Id=?";
            $stmt = $conn->prepare($sql);
            $stmt->bind_param('ssi', $name, $scl, $id);
            if($stmt->execute()){
               echo json_encode(array('status'=>'success'));
             } else{
               http_response_code(500);
               echo json_encode(array('error'=>'Failed to update userdata.'));
             }
             break;
             case 'DELETE':
               parse_str(file_get_contents("php://input"), $_DELETE);
               $id = $_DELETE['Id'];
               $sql = "DELETE FROM child WHERE Id = ?";
               $stmt = $conn->prepare($sql);
               $stmt->bind_param('i',$id);

               if($stmt -> execute()){
                  echo json_encode(array('status'=>'success'));
               }
               else{
                  http_response_code(500);
                  echo json_encode(array('error'=>'Failed to delete userdata.'));
               }
               break;
         default:
         http_response_code(400);
        echo json_encode(array('error'=>'Invalid request method'));
}
$conn->close();
?>