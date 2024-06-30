<?php
    if(isset($_POST['submit']))
    {
        $checker1 = $_COOKIE['TestId'];
        $checker2 = $_COOKIE['Id'];
        $checker3 = $_REQUEST['date'];
        $checker4 = $_REQUEST['timeslots'];
        $con=mysqli_connect('localhost','root','','hospital_database');
         $sql3 = "INSERT INTO pathology_bookings
                  VALUES(NULL,'$checker1','$checker2','$checker3','$checker4')";
        mysqli_query($con,$sql3);
        header('location: Pathology.php');
    }
?>
<html>
    <head>
        <title>
            Test Booking
        </title>
        <link rel="stylesheet" href="Pathology_booking.css?v=<?php echo time(); ?>">
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
            Test Booking
        </div>
        <div class="TestName">
            <h2><?php echo $_COOKIE['TestName'];?></h2>
        </div>
        <div class="PDetails">
            <?php echo "Patient Id:- ".$_COOKIE['Id']."&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp"."Patient Name:- ".$_COOKIE['Name'];?>
        </div>
        <form class="chooseDate" method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
            <div class="datestamp">
                Choose a date &nbsp
                <input type="date" name="date" style="width: 40%; border-radius: 10px; font-family: Bankgothic md bt; font-size: 70%;" required>
            </div>
            <div class="timeSlot">
                <h2>
                Select time slot:-
                </h2>
                <select name="timeslots" id="" style="width: 20%; height: 30%; font-family: Bankgothic md bt; font-size: 120%; border-radius: 10px; background-color: rgb(148, 148, 184); color: white; border-style: solid; border-width: 2px; border-color: black;" required>
                    <option value="" selected disabled>--Select--</option>
                    <option value="07:00-08:00">07:00-08:00</option>
                    <option value="08:00-09:00">08:00-09:00</option>
                    <option value="09:00-10:00">09:00-10:00</option>
                    <option value="10:00-11:00">10:00-11:00</option>
                    <option value="11:00-12:00">11:00-12:00</option>
                    <option value="12:00-13:00">12:00-13:00</option>
                    <option value="13:00-14:00">13:00-14:00</option>
                    <option value="14:00-15:00">14:00-15:00</option>
                    <option value="15:00-16:00">15:00-16:00</option>
                    <option value="16:00-17:00">16:00-17:00</option>
                    <option value="17:00-18:00">17:00-18:00</option>
                    <option value="18:00-19:00">18:00-19:00</option>
                </select>
            </div>
            <div class="dateSubmit">
                <button type="submit" class="submit" name="submit">
                    Confirm
                </button>
            </div>
        </form>
        <div class="foot">
        </div>
    </body>
</html>