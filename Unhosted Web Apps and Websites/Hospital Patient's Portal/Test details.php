<html>
    <head>
        <title>
            Test Details
        </title>
        <link rel="stylesheet" href="Test details.css?v=<?php echo time(); ?>">
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
            Test Details
        </div>
        <div class="detailArea">
            <div class="TestDetailArea">
                <div class="contentArea">
                    <h2><?php echo $_COOKIE['TestName'];?></h2>
                </div>
                <div class="contentArea">
                    Specimen_type:- <?php echo $_COOKIE['Specimen'];?>
                </div>
                <div class="contentArea">
                    Parameters covered:-
                    <?php
                         $temp=$_COOKIE['TestId'];
                         $con=mysqli_connect('localhost','root','','hospital_database');
                         $sql="SELECT Parameter_name FROM test_parameters WHERE Test_id=$temp;";
                         $res=mysqli_query($con,$sql);
                         echo "<ul>";
                         while($row = mysqli_fetch_array($res))
                         {
                            echo"<li>";
                            echo $row['Parameter_name'];
                            echo"</li>";
                         }
                         echo "</ul>";
                         mysqli_close($con);
                         
                    ?>
                </div>
                <div class="contentArea">
                         &#9432;
                         <?php
                         echo $_COOKIE['Information'];
                         ?>
                </div>

                <div class="contentArea">
                    Price:- <?php echo $_COOKIE['Price'];?>
                </div>
               
            </div>
        </div>
        <div class="buttonBanner">
            <div class="button" onclick="location.href='Pathology_booking.php'">
                Book A Test
            </div>
        </div>
        <div class="foot">
        </div>
    </body>
</html>