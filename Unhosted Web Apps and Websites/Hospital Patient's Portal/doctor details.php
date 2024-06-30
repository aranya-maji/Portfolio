<html>
    <head>
        <title>
            Doctor Details
        </title>
        <link rel="stylesheet" href="doctor details.css?v=<?php echo time(); ?>">
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
            Doctor Details
        </div>
        <div class="detailArea">
            <div class="docImageArea">
                <div class="dp">
                    <img src="<?php echo $_COOKIE['DocImage'];?>" alt="" height="150%" width="auto" style="padding-top: 50%;">
                </div>
            </div>
            <div class="docDetailArea">
                <div class="contentArea">
                    <h2>Dr. <?php echo $_COOKIE['DocName'];?></h2>
                </div>
                <div class="contentArea">
                    Degree:-
                    <?php
                        $checker1 = $_COOKIE['DocId'];
                        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
                        $sql = "SELECT Degree FROM doctor_degree_details WHERE Doc_Id = '$checker1'";
                        $result = mysqli_query($con,$sql);
                        while($row = mysqli_fetch_array($result))
                        {
                            echo $row['Degree'].'&nbsp';
                        }
                        mysqli_close($con);
                    ?>
                </div>
                <div class="contentArea">
                    Experience years:- <?php echo $_COOKIE['DocExp'];?>
                </div>
                <div class="contentArea">
                    Email:- <?php echo $_COOKIE['DocEmail'];?>
                </div>
                <div class="contentArea">
                    Phone:-
                    <?php
                        $checker2 = $_COOKIE['DocId'];
                        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
                        $sql = "SELECT Phone_number FROM doctor_contact_details WHERE Doc_Id = '$checker2'";
                        $result = mysqli_query($con,$sql);
                        while($row = mysqli_fetch_array($result))
                        {
                            echo $row['Phone_number'].'&nbsp';
                        }
                        mysqli_close($con);
                    ?>
                </div>
            </div>
        </div>
        <div class="buttonBanner">
            <div class="button" onclick="location.href='schedule.php'">
                Schedule an appointment
            </div>
        </div>
        <div class="foot">
        </div>
    </body>
</html>