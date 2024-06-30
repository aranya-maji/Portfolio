<?php
    if(isset($_POST['submit']))
    {
        $checker1 = $_COOKIE['Id'];
        $checker2 = $_COOKIE['DocId'];
        $checker3 = $_COOKIE['DocCab'];
        $checker4 = $_COOKIE['date'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql1 = "INSERT INTO appointment_details
                    VALUES(NULL,'$checker1','$checker2','$checker3','$checker4')";
        mysqli_query($con,$sql1);
        $sql2 = "SELECT App_Number
                    FROM appointment_details
                    WHERE Patient_id = '$checker1'
                    AND Doctor_id = '$checker2'
                    ORDER BY App_Number DESC limit 1";
        $result = mysqli_query($con,$sql2);
        while($row = mysqli_fetch_array($result))
        {
            $checker5 = $row['App_Number'];
            $checker6 = $_REQUEST['PaymentMethods'];
            $checker7 = $_COOKIE['DocFees'];
            $checker8 = date("Y-m-d");
            $checker9 = date("H:i:s");
            $sql3 = "INSERT INTO payment_details
                    VALUES(NULL,'$checker1','$checker2','$checker5','$checker6','$checker7','$checker8','$checker9')";
            mysqli_query($con,$sql3);
        }
        header('location: home.php');
    }
?>
<html>
    <head>
        <title>
            Appointment
        </title>
        <link rel="stylesheet" href="appointment.css?v=<?php echo time(); ?>">
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
                The day is
                <?php
                    echo $_COOKIE['day'];
                ?>
                and the time will be
                <?php
                    echo $_COOKIE['timing'];
                ?>
            </div>
            <div class="paymentArea">
                Select Payment Method to pay Rs
                <?php
                    echo $_COOKIE['DocFees'];
                ?>
                &nbsp&nbsp&nbsp&nbsp
                <select name="PaymentMethods" id="" style="width: 20%; height: 30%; font-family: Bankgothic md bt; font-size: 90%; border-radius: 10px; background-color: rgb(148, 148, 184); color: white; border-style: solid; border-width: 2px; border-color: black;" required>
                    <option value="" selected disabled>--Select--</option>
                    <option value="PhonePe">PhonePe</option>
                    <option value="Paytm">Paytm</option>
                    <option value="PayPal">PayPal</option>
                    <option value="UPI">UPI</option>
                    <option value="Netbanking">Netbanking</option>
                </select>
            </div>
            <div class="dateSubmit">
                <button type="submit" class="submit" name="submit">
                    Pay & Confirm
                </button>
            </div>
        </form>
        <div class="foot">
        </div>
    </body>
</html>