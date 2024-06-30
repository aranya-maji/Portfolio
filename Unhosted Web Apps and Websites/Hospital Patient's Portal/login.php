<?php
    if(isset($_POST['submit']))
    {
        $checker1 = $_REQUEST['Uname'];
        $checker2 = $_REQUEST['Name'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql1 = "SELECT *
                    FROM patient_details
                    WHERE BINARY Username = '$checker1'
                    AND Name = '$checker2'";
        $result = mysqli_query($con,$sql1);
        if(mysqli_num_rows($result) == 0)
        {
            mysqli_close($con);
            header("location: check3.php");
        }
        else
        {
            while($row = mysqli_fetch_array($result))
            {
                $checker3 = $_REQUEST['Password'];
                if($checker3 === $row['Password'])
                {
                    mysqli_close($con);
                    setcookie('Id',$row['P_Id'],time() + 86400,'/');
                    setcookie('Name',$row['Name'],time() + 86400,'/');
                    setcookie('Uname',$row['Uname'],time() + 86400,'/');
                    header("location: home.php");
                } 
                else
                {
                    header("location: check1.php");
                }
            }
        }
    }
?>
<html>
    <head>
        <title>
            Login
        </title>
        <link rel="stylesheet" href="login.css?v=<?php echo time(); ?>">
        <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
    </head>
    <body>
        <div class="imageBanner">
            <div class="logo">
                <img src="logo.jfif" alt="">
            </div>
            <div class="gap">

            </div>
            <div class="who">
                <img src="home banner.jpg" alt="">
            </div>
        </div>
        <div class="captionBanner">
            Login
        </div>
        <form action="<?php echo $_SERVER['PHP_SELF'];?>" method="POST" class="form">
            <div class="contentRow">
                <div class="contentPlatform">
                    Name&nbsp
                    <input type="text" name="Name" style="height: 20%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Username&nbsp
                    <input type="text" name="Uname" style="height: 20%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Password&nbsp
                    <input type="password" name="Password" style="height: 20%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
            </div>
            <div class="buttonArea">
                <button type="submit" class="submitButton" name="submit">
                    Submit
                </button>
            </div>
        </form>
        <div class="foot">
        </div>
    </body>
</html>