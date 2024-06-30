<?php
    if(isset($_POST['submit']))
    {
        header('location: Past appointments.php');
    }
?>
<html>
    <head>
        <title>
            Home
        </title>
        <link rel="stylesheet" href="home.css?v=<?php echo time(); ?>">
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
            <div class="marquee">
                <marquee behavior="" direction="" scrollamount="10">Completed 50 Years of excellence || Over a million successful surgeries || More than a million happy patients</marquee>
            </div>
            <div class="partition">

            </div>
            <div class="PAArea">
                <div class="greet">
                    Hi
                    <?php
                        echo $_COOKIE['Name'];
                    ?>
                    !
                </div>
                <form action="" method= "POST" class="form">
                    <div class="PAButtonArea">
                        <button type="submit" class="PAButton" name="submit">
                            Past Appointments
                        </button>
                    </div>
                </form>
            </div>
        </div>
        <div class="promoBanner">
            <video src="promo.mp4" height="90%" controls>
                <source src="promo.mp4" type="video/mp4">
            </video>
        </div>
        <div class="optionBar">
            <div class="optionArea">
                <div class="pathology">
                    <button name="" id="" class="pathologyButton" onclick="location.href='Pathology.php'">
                        Pathology    
                    </button>
                </div>
            </div>
            <div class="optionArea">
                <div class="departments">
                    <select name="" id="" ondblclick="location.href=this.value" onchange="location.href=this.value" style="font-size: 90%; border-radius: 10px; background-color: rgb(148, 148, 184); color: white; font-family: Bankgothic md bt; width: 95%;">
                        <option value="" disabled selected>--Departments--</option>
                        <option value="Cardiology.php">Cardiology</option>
                        <option value="Dental sciences.php">Dental sciences</option>
                        <option value="Dermatology.php">Dermatology</option>
                        <option value="Emergency medicine.php">Emergency medicine</option>
                        <option value="Endocrinology.php">Endocrinology</option>
                        <option value="ENT.php">ENT</option>
                        <option value="Gastroenterology.php">Gastroenterology</option>
                        <option value="Infertility medicine.php">Infertility medicine</option>
                        <option value="Internal Medicine.php">Internal Medicine</option>
                        <option value="Medicine department.php">Medicine department</option>
                        <option value="Neurology.php">Neurology</option>
                        <option value="Nurse department.php">Nurse Department</option>
                        <option value="Gynaecology.php">Obstetrics and Gynaecology</option>
                        <option value="Oncology.php">Oncology</option>
                        <option value="Ophthalmology.php">Ophthalmology</option>
                        <option value="Orthopaedics.php">Orthopaedics</option>
                        <option value="Paediatrics.php">Paediatrics</option>
                        <option value="Physiotherapy.php">Physiotherapy and Rehabilitation</option>
                        <option value="Psychiatry.php">Psychiatry</option>
                    </select>
                </div>
            </div>
            <div class="optionArea">
                <div class="services">
                    <select name="" id="" ondblclick="location.href=this.value" onchange="location.href=this.value"style="font-size: 90%; border-radius: 10px; background-color: rgb(148, 148, 184); color: white; font-family: Bankgothic md bt; width: 95%;">
                        <option value="" selected disabled>--Services--</option>
                        <option value="Ambulance services.php">Ambulance services</option>
                        <option value="Emergency care unit.php">Emergency care unit</option>
                        <option value="Paramedics.php">Paramedics</option>
                        <option value="Rapid COVID test.php">Rapid COVID test</option>
                    </select>
                </div>
            </div>
            <div class="optionArea">
                <div class="contactUs">
                    <select name="" id="" ondblclick="location.href=this.value" onchange="location.href=this.value" style="font-size: 90%; border-radius: 10px; background-color: rgb(148, 148, 184); color: white; font-family: Bankgothic md bt; width: 95%;">
                        <option value="" selected disabled>--Contact Us--</option>
                        <option value="Head of Departments.php">Head Of Departments</option>
                        <option value="Helpdesk.php">Helpdesk(Toll-Free)</option>
                        <option value="Reception desk.php">Reception desk</option>
                    </select>
                </div>
            </div>
        </div>
        <div class="foundersHeading">
            Our Founders
        </div>
        <div class="foundersArea">
            <div class="foundersCompartment">
                <div class="foundersImageArea">
                    <div class="foundersImage">
                        <img src="Aranya.jpg" alt="" height="200%" width="auto" style="padding-right: 30%; padding-top: 50%;">
                    </div>
                </div>
                <div class="foundersTextArea">
                    <br><br><br><br>
                    <p>
                        <h2>Aranya Maji</h2>
                        He is one of the founders of the AGIP Medics.
                        He worked upon executing every decision that was
                        made to bring this prestigious Instituition to the
                        level it is in today and brought technical integrity
                        to it.
                    </p>
                </div>
            </div>
            <div class="foundersCompartment">
                <div class="foundersImageArea">
                    <div class="foundersImage">
                        <img src="Gargi.jpeg" alt="" height="130%" width="auto" style="padding-top: 20%;">
                    </div>
                </div>
                <div class="foundersTextArea">
                    <br><br><br><br>
                    <p>
                        <h2>Gargi Jain</h2>
                        She is one of the founders of the AGIP Medics.
                        She established the most complex structural backbone and
                        successfully implemented it by leading the team on which
                        the Instituition functions today, making the functioning of AGIP Medics
                        easy and efficient for its employees and its patients.
                    </p>
                </div>
            </div>
            <div class="foundersCompartment">
                <div class="foundersImageArea">
                    <div class="foundersImage">
                        <img src="Ishita.jpg" alt="" height="130%" width="auto" style="padding-top: 25%;">
                    </div>
                </div>
                <div class="foundersTextArea">
                    <br><br><br><br>
                    <p>
                        <h2>Ishita Sethi</h2>
                        She is one of the founders of the AGIP Medics.
                        She worked upon making platforms for AGIP Medics
                        making the Instituition reachable and easily accesible
                        to the masses.
                    </p>
                </div>
            </div>
            <div class="foundersCompartment">
                <div class="foundersImageArea">
                    <div class="foundersImage">
                        <img src="Prakhar.jpeg" alt="" height="180%" width="auto" style="padding-top: 25%;">
                    </div>
                </div>
                <div class="foundersTextArea">
                    <br><br><br><br>
                    <p>
                        <h2>Prakhar Kumar Singh</h2>
                        He is one of the founders of the AGIP Medics.
                        He is the mastermind behind all the plans, ideas
                        and facilities that are provided by the AGIP Medics
                        today to its patients, making the Instituition the
                        most versatile among all others in the same field.
                    </p>
                </div>
            </div>
        </div>
        <div class="foot">

        </div>
    </body>
</html>