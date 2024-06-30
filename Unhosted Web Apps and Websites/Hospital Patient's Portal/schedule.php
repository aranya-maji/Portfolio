<?php
    if(isset($_POST['submit']))
    {
        $timestamp = $_REQUEST['date'];
        $day = date('l',strtotime($timestamp));
        setcookie('day',$day,time() + 86400,'/');
        setcookie('date',$timestamp,time() + 86400,'/');
        $checker1 = $_COOKIE['DocId'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        if($day == "Monday")
        {
            $sql1 = "SELECT Monday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Monday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Tuesday")
        {
            $sql1 = "SELECT Tuesday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Tuesday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Wednesday")
        {
            $sql1 = "SELECT Wednesday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Wednesday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Thursday")
        {
            $sql1 = "SELECT Thursday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Thursday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Friday")
        {
            $sql1 = "SELECT Friday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Friday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Saturday")
        {
            $sql1 = "SELECT Saturday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Saturday_timings'],time() + 86400,'/');
            }
        }
        else if($day == "Sunday")
        {
            $sql1 = "SELECT Sunday_timings
                    FROM doctor_schedule
                    WHERE Doc_Id = '$checker1'";
            $result = mysqli_query($con,$sql1);
            while($row = mysqli_fetch_array($result))
            {
                setcookie('timing',$row['Sunday_timings'],time() + 86400,'/');
            }
        }
        mysqli_close($con);
        header('location: appointment.php');
    }
?>
<html>
    <head>
        <title>
            Appointment
        </title>
        <link rel="stylesheet" href="schedule.css?v=<?php echo time(); ?>">
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
            Appointment
        </div>
        <div class="docName">
            <h2>Dr. <?php echo $_COOKIE['DocName'];?></h2>
        </div>
        <div class="PDetails">
            <?php echo "Patient Id:- ".$_COOKIE['Id']."&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp"."Patient Name:- ".$_COOKIE['Name'];?>
        </div>
        <form class="chooseDate" method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
            <div class="datestamp">
                Choose a date &nbsp
                <input type="date" name="date" style="width: 40%; border-radius: 10px; font-family: Bankgothic md bt; font-size: 70%;" required>
            </div>
            <div class="dateSubmit">
                <button type="submit" class="submit" name="submit">
                    Check availability
                </button>
            </div>
        </form>
        <div class="foot">
        </div>
    </body>
</html>