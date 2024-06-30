<?php
    if(isset($_POST['Test']))
    {
        $checker1 = $_REQUEST['Test'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql = "SELECT *
                FROM pathology_tests
                WHERE Test_id = '$checker1'";
        $result = mysqli_query($con,$sql);
        while($row = mysqli_fetch_array($result))
        {
            setcookie('TestId',$row['Test_id'],time() + 86400,'/');
            setcookie('TestName',$row['Test_name'],time() + 86400,'/');
            setcookie('Price',$row['Prices'],time() + 86400,'/');
            setcookie('Specimen',$row['Specimen_Type'],time() + 86400,'/');
            setcookie('Parameters',$row['No_of_parameters'],time() + 86400,'/');                
            setcookie('Information',$row['Info'],time() + 86400,'/');              
            header("location: Test details.php");
        }
    }
?>
<html>
    <head>   
        <title>
            Pathology
        </title>
        <link rel="stylesheet" href="Pathology.css?v=<?php echo time(); ?>">
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
            <img src="Pathology.jpg" alt="" height="200%" width="auto">
        </div>
        <div class="captionTextArea">

        </div>
        <div class="captionText">
            Pathology
        </div>
        <?php
            $con = mysqli_connect('localhost','root',NULL,'hospital_database');
            $sql = "SELECT * FROM pathology_tests; ";
            $res = mysqli_query($con,$sql);
            while($row = mysqli_fetch_array($res))
            {
                $checker2 = $row['Test_id'];
                echo "<form  method='POST' class='form'>";
                echo "<button type='submit' class='submit' name='Test' value='";
                echo $row['Test_id'];
                echo "'>";
                echo "<div class='imageArea'>";
                echo "<div class='dp'>";
                $checker3 = $row['Image'];
                echo "<img src='$checker3' alt='' height='120%' width='auto' style='padding-top: 20%;'>";
                echo "</div>";
                echo "</div>";
                echo "<div class='detailArea'>";
                echo "<p>";
                echo "<h2>";
                echo $row['Test_name'];
                echo "</h2>";
                echo "Prices:- INR ".$row['Prices'];
                echo "<br>";
                echo "<br>";
                echo $row['No_of_parameters']." parameters covered";
                echo "</p>";
                echo "</div>";
                echo "</button>";
                echo "</form>";
            }
            mysqli_close($con);
        ?>
        <div class="foot">
        </div>
    </body>
</html>