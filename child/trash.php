<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "study";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
 }

 $method = $_SERVER['REQUEST_METHOD'];
 switch($method){
    case 'POST':
        $name = $_POST['Name'];
        $scl = $_POST['School'];
        $sql = "DELETE FROM child WHERE Name = ?";
      $stmt = $conn->prepare($sql);
      if($stmt){
        $stmt->bind_param('s',$name);
        if($stmt->execute()){
            echo "Record deleted successfully WHERE Name = ".$name;
        }
        else{
            echo "Error deleting record: ".$stmt->error;
        }
        $stmt->close();
      }else{
        echo "Error: ".$conn->error;
      }
      break;
    }
   $conn->close();
   //this program works when the user submits the form,
   //it will look if there is any row with name enterd by the user and delete it automatically;
 /*  if($conn->query($sql) === TRUE){
    echo "Records are deleted successfully";
  }
  else{
    echo "Error: ".$conn->error;
  }*/ //this is used in case you're directly querying the db, (no variables used),      $sql = "DELETE FROM child WHERE Id > 2";

?>

<script>
      document.getElementById('submit').addEventListener('click',function(){
    style.cursor =  'text';
       });
    document.getElementById('submit').addEventListener('click',function(){
       style.cursor =  'pointer';
       });
    </script>
    <script>
        document.addEventListener('DOMContentLoaded', function(){
            load();
            document.getElementById('form1').addEventListener('submit',(event)=>{
                event.preventDefault();
                add();
            })
        })

       function add(){
        var name = document.getElementById('name').value;
        var scl = document.getElementById('school').value;

        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function(){
            if(xhr.readyState === XMLHttpRequest.DONE ){
                if(xhr.status === 200){
                    load();
                }
                else{
                    console.error('Failed to record user data.');
                }
            }
        };
        xhr.open('POST','child.php',true);
        xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
        xhr.send('Name='+name+'&School='+scl);
       }

       function load(){
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function (){
            if(xhr.readyState === XMLHttpRequest.DONE){
                if(xhr.status === 200){
                    diplay(JSON.parse(xhr.responseText));
                }
                else{console.error('Failed to laod userdata.')
            }
        }
        };
        xhr.open('GET','child.php',true);
        xhr.send();
    }
    </script>