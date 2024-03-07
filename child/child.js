document.addEventListener('DOMContentLoaded', function(){
    load();
    document.getElementById('form1').addEventListener('submit',function (event){
        event.preventDefault();
        add();
    });
});

 function add(){
    var name = document.getElementById('name').value;
    var scl = document.getElementById('school').value;

    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if(xhr.readyState === XMLHttpRequest.DONE){
            if(xhr.status === 200){
               load();
            }
            else{
                console.error('Failed to record userdata.')
            }
        }
    };
    xhr.open('POST','child.php',true);
    xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
    xhr.send('Name='+name+'&School='+scl); //where strings in the quotes are tCol;
 }
 function load(){
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function (){
        if(xhr.readyState === XMLHttpRequest.DONE){
            if(xhr.status === 200){
                display(JSON.parse(xhr.responseText));
            }
            else{
                console.error('Failed to load userdata.');
            }
        }
    };
    xhr.open('GET','child.php',true);
    xhr.send();
 }

 function display(childs){
    var userOutPut = document.getElementById('userdata');
    userOutPut.innerHTML = "";
    childs.forEach(function (child) {
        var tableRow = document.createElement('div');
        tableRow.innerHTML = `
        <p>Id: ${child.Id}</p>
                <p>Name: ${child.Name}</p>
                <p>School: ${child.School}</p>
                <p>
                    <button type="button" id="edit" onclick="edit(${child.Id})">Edit</button>
                    <button type="button" id="delete" onclick="deleteData(${child.Id})">Delete</button>
                </p>
        `
        userOutPut.appendChild(tableRow);
    });
 }

 function  deleteData(id){
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function (){
        if(xhr.readyState === XMLHttpRequest.DONE){
            if(xhr.status === 200){
                load();
            }
            else{
                console.error("Failed to delete userdata.");
            }
        } 
    };
    xhr.open('DELETE','child.php',true);
    xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
    xhr.send("Id="+id);
 }

 function edit(id){
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function(){
        if(xhr.readyState === XMLHttpRequest.DONE){
            if(xhr.status === 200){
                var childs = JSON.parse(xhr.responseText);
                childs.forEach((child) => {
                    if(child.Id = id){
                        showEditForm(child);
                    }
                })
        }
        else{
            console.error('Failed to fetch userdata for editting.')
        }
    }
};
    xhr.open('GET','child.php',true);
    xhr.send();
 }
 function showEditForm(child){
    var editForm = document.createElement('form');
    editForm.innerHTML = `
    <h2>Edit the profile</h2>
    <label for="edit-name">Name: </label>
    <input type="text" id="edit-name" name="Edit-Name" maxlength="60" value="${child.Name}" autofocus required> <br><br>
    <label for="edit-school">School: </label>
    <input type="text" id="edit-school" maxlength="60" value="${child.School}" required> <br> <br>

        <button type="button" onclick="update(${child.Id})">Update</button>
        <button type="button" onclick="cancelEdit()">Cancel</button>
    `;
    var userDetails = document.getElementById("userdata");
    userDetails.innerHTML = "";
    userDetails.appendChild(editForm);
 }
 
 function update(id){
    var newname = document.getElementById('edit-name').value;
    var newscl = document.getElementById('edit-school').value;
    console.log(newname+"\n"+newscl);

    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function (){
        if(xhr.readyState === XMLHttpRequest.DONE){
            if(xhr.status === 200 ){
                load();
            }
            else{
                console.error('Failed to update userdata.');
            }
        }
    };
    xhr.open('PUT','child.php',true);
    xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
    xhr.send('Id='+ id +'&Name='+ newname +'&School='+ newscl ); //the table col in the quotes are passed in the php put['']; remember to write them well!!!
 }
function cancelEdit(){
    load();
}