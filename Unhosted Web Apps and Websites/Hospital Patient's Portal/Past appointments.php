<?php
    if(isset($_POST['submit']))
    {
        $checker1 = $_REQUEST['submit'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql1 = "SELECT * FROM appointment_details WHERE App_Number = '$checker1'";
        $result22 = mysqli_query($con,$sql1);
        while($row = mysqli_fetch_array($result22))
        {
            $checker11 = $row['Doctor_id'];
            $sql11 = "SELECT Name FROM doctor_details WHERE Doc_Id = '$checker11'";
            $result11 = mysqli_query($con,$sql11);
            while($row1 = mysqli_fetch_array($result11))
            {
                setcookie('DocName',$row1['Name'],time() + 86400,'/');
            }
        }
        header('location: feedback.php');
    }
?>
<html>
    <head>
        <title>
            Past Appointments
        </title>
        <link rel="stylesheet" href="Past appointments.css?v=<?php echo time(); ?>">
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
            Past Appointments
        </div>
        <?php
            $checker1 = $_COOKIE['Id'];
            $con = mysqli_connect('localhost','root',NULL,'hospital_database');
            $sql1 = "SELECT * FROM appointment_details WHERE Patient_id = '$checker1'";
            $result1 = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result1))
            {
                echo '<form class="contentArea" method="POST" action="';
                echo $_SERVER['PHP_SELF'];
                echo '">';
                echo '<button class="contentAreaButton" type="submit" name="submit" value="';
                echo $row['App_Number'];
                echo '">';
                echo 'App Id:- ';
                echo $row['App_Number'];
                echo '&nbsp&nbsp';
                $checker3 = $row['Doctor_id'];
                $sql3 = "SELECT Name, Cabin_no, Specialization FROM doctor_details WHERE Doc_Id = '$checker3'";
                $result3 = mysqli_query($con,$sql3);
                while($row2 = mysqli_fetch_array($result3))
                {
                    echo 'Doctor Name:- ';
                    echo $row2['Name'];
                    echo '&nbsp&nbsp';
                    echo 'Cabin Number:- ';
                    echo $row2['Cabin_no'];
                    echo '&nbsp&nbsp';
                    echo 'Specialization:- ';
                    echo $row2['Specialization'];
                    echo '&nbsp&nbsp';
                }
                echo 'Date of Appointment:- ';
                echo $row['Date_of_appointment'];
                echo '</button>';
                echo '</form>';
            }
        ?>
        <div class="foot">
        </div>
    </body>
</html>