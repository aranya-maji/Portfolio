<?php
    if(isset($_POST['submit']))
    {
        $checker1 = $_COOKIE['DocId'];
        $checker2 = $_COOKIE['Id'];
        $checker3 = $_REQUEST['feedback'];
        $checker4 = $_REQUEST['rating'];
        $checker5 = date("Y-m-d");
        $con = mysqli_connect('localhost','root',NULL,'hospital_database');
        $sql = "INSERT INTO feedback_details
                VALUES(NULL,'$checker1','$checker2','$checker3','$checker4','$checker5')";
        mysqli_query($con,$sql);
        header('Location: Past appointments.php');
    }
?>
<html>
    <head>
        <title>
            Feedback
        </title>
        <link rel="stylesheet" href="feedback.css?v=<?php echo time(); ?>">
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
            Feedback
        </div>
        <form class="form" method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
            <div class="DocName">
                <h2>Feedback for Dr. 
                    <?php
                        echo $_COOKIE['DocName'];
                    ?>
                </h2>
            </div>
            <div class="feedbackArea">
                <textarea name="feedback" id="" cols="30" rows="10" style="resize: none; width: 50%; height: 90%; overflow-y: scroll; font-family: Bankgothic md bt; font-size: 120%;" placeholder="Write your feedback here.........." required></textarea>
            </div>
            <div class="ratingArea">
                Rating &nbsp&nbsp
                1 <input type="radio" name="rating" value="1" required>
                &nbsp&nbsp
                2 <input type="radio" name="rating" value="2" required>
                &nbsp&nbsp
                3 <input type="radio" name="rating" value="3" required>
                &nbsp&nbsp
                4 <input type="radio" name="rating" value="4" required>
                &nbsp&nbsp
                5 <input type="radio" name="rating" value="5" required>
            </div>
            <div class="buttonArea">
                <button type="submit" class="submit" name="submit">
                    Submit feedback
                </button>
            </div>
        </form>
        <div class="foot">
        </div>
    </body>
</html>