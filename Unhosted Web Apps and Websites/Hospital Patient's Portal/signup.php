<?php
    if(isset($_POST['submit']))
    {
        if($_POST['Password'] !== $_POST['ConPassword'])
        {
            header("location: check1.php");
        }
        else
        {
            $checker = $_REQUEST['Uname'];
            $con = mysqli_connect('localhost','root',NULL,'hospital_database');
            $sql1 = "SELECT Username
                        FROM patient_details
                        WHERE Username = '$checker'";
            $result = mysqli_query($con,$sql1);
            if(mysqli_num_rows($result) == 0)
            {
                $N = $_REQUEST['Name'];
                $A = $_REQUEST['Address'];
                $D = $_REQUEST['DOB'];
                $G = $_REQUEST['Gender'];
                $B = $_REQUEST['BloodGroup'];
                $AN = $_REQUEST['ANo'];
                $U = $_REQUEST['Uname'];
                $P = $_REQUEST['Password'];
                $PH = $_REQUEST['Phno'];
                $sql2 = "INSERT INTO patient_details
                            VALUES(NULL,'$N','$A','$D','$G','$B','$AN','$U','$P')";
                mysqli_query($con,$sql2);
                $sql3 = "SELECT P_Id FROM patient_details WHERE Username = '$U'";
                $result1 = mysqli_query($con,$sql3);
                while($row = mysqli_fetch_array($result1))
                {
                    $PU = $row['P_Id'];
                    setcookie('Id',$row['P_Id'],time() + 86400,'/');
                    $sql4 = "INSERT INTO patient_contact_details VALUES(NULL,'$PU','$PH')";
                    mysqli_query($con,$sql4);
                }
                mysqli_close($con);
                setcookie('Name',$_REQUEST['Name'],time() + 86400,'/');
                setcookie('Uname',$_REQUEST['Uname'],time() + 86400,'/');
                header("location: home.php");
            }
            else
            {
                mysqli_close($con);
                header("location: check2.php");
            }
        }
    }
?>
<html>
    <head>
        <title>
            Sign Up
        </title>
        <link rel="stylesheet" href="signup.css?v=<?php echo time(); ?>">
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
            Sign Up
        </div>
        <form action="<?php echo $_SERVER['PHP_SELF'];?>" method="POST" class="form">
            <div class="contentRow">
                <div class="contentPlatform">
                    Name&nbsp
                    <input type="text" name="Name" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Address&nbsp
                    <input type="text" name="Address" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Date of Birth&nbsp
                    <input type="date" name="DOB" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
            </div>
            <div class="contentRow">
                <div class="contentPlatform">
                    Gender&nbsp
                    <select name="Gender" id="" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                        <option value="" disabled selected>--Select--</option>
                        <option value="M">Male</option>
                        <option value="Fe">Female</option>
                        <option value="Others">Others</option>
                    </select>
                </div>
                <div class="contentPlatform">
                    Blood Group&nbsp
                    <input type="text" name="BloodGroup" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Aadhar Number&nbsp
                    <input type="text" name="ANo" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
            </div>
            <div class="contentRow">
                <div class="contentPlatform">
                    Username&nbsp
                    <input type="text" name="Uname" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Password&nbsp
                    <input type="password" name="Password" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
                <div class="contentPlatform">
                    Confirm Password&nbsp
                    <input type="password" name="ConPassword" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
                </div>
            </div>
            <div class="contentRow">
                <div class="contentPlatform">
                    Phone Number&nbsp
                    <input type="text" name="Phno" style="height: 25%; width: 40%; font-family: Bankgothic md bt; font-size: 90%;" required>
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