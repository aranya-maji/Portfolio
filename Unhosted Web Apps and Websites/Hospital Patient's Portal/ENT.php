<?php
    if(isset($_POST['Doc']))
    {
        $checker1 = $_REQUEST['Doc'];
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql = "SELECT *
                FROM doctor_details
                WHERE Doc_Id = '$checker1'";
        $result = mysqli_query($con,$sql);
        while($row = mysqli_fetch_array($result))
        {
            setcookie('DocId',$row['Doc_Id'],time() + 86400,'/');
            setcookie('DocName',$row['Name'],time() + 86400,'/');
            setcookie('DocExp',$row['Exp_years'],time() + 86400,'/');
            setcookie('DocEmail',$row['Email'],time() + 86400,'/');
            setcookie('DocImage',$row['Image'],time() + 86400,'/');
            setcookie('DocCab',$row['Cabin_no'],time() + 86400,'/');
            setcookie('DocFees',$row['Fees'],time() + 86400,'/');
        }
        header("location: doctor details.php");
    }
?>
<html>
    <head>
        <title>
            ENT
        </title>
        <link rel="stylesheet" href="ENT.css?v=<?php echo time(); ?>">
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
            <img src="ENT.jpg" alt="" height="100%" width="auto">
        </div>
        <div class="captionTextArea">

        </div>
        <div class="captionText">
            ENT
        </div>
        <?php
            $con = mysqli_connect('localhost','root',NULL,'hospital_database');
            $sql = "SELECT  Doc_Id , Name , Image , Fees , Exp_years FROM doctor_details WHERE Specialization='ENT'";
            $res = mysqli_query($con,$sql);
            while($row = mysqli_fetch_array($res))
            {
                $checker2 = $row['Doc_Id'];
                $sql1 = "SELECT Degree FROM doctor_degree_details WHERE Doc_Id = '$checker2'";
                $result1 = mysqli_query($con,$sql1);
                echo "<form  method='POST' class='form'>";
                echo "<button type='submit' class='submit' name='Doc' value='";
                echo $row['Doc_Id'];
                echo "'>";
                echo "<div class='imageArea'>";
                echo "<div class='dp'>";
                $checker3 = $row['Image'];
                echo "<img src='$checker3' alt='' height='170%' width='auto' style='padding-top: 60%;'>";
                echo "</div>";
                echo "</div>";
                echo "<div class='detailArea'>";
                echo "<p>";
                echo "<h2>";
                echo $row['Name'];
                echo "</h2>";
                while($row1 = mysqli_fetch_array($result1))
                {
                    echo $row1['Degree']."&nbsp";
                }
                echo "<br><br>";
                echo "Experience Years:- ".$row['Exp_years'];
                echo "&nbsp&nbsp&nbsp&nbsp&nbsp";
                echo "Fees:- ".$row['Fees'];
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