<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <!--<link rel="shortcut icon" href="/docs-assets/ico/favicon.png"> -->

    <title>TAES-Tsinghua Algorithm Evaluation System</title>

    <!-- Bootstrap core CSS -->
    <link href="dist/css/bootstrap.css" rel="stylesheet">
    <!-- Bootstrap theme -->
    <link href="dist/css/bootstrap-theme.min.css" rel="stylesheet">
    <!-- Custom styles for this template -->
    <link href="css/theme.css" rel="stylesheet">
    <link href="css/signin.css" rel="stylesheet">
    <!-- Just for debugging purposes. Don't actually copy this line! -->
    <!--[if lt IE 9]><script src="{{ page.base_url }}docs-assets/js/ie8-responsive-file-warning.js"></script><![endif]-->
    <!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
      <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
    <![endif]-->
  </head>

  <body>
    <!-- Fixed navbar -->
    <div class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="#">TAES Bingo!</a>
        </div>
        <div class="navbar-collapse collapse">
          <ul class="nav navbar-nav">
            <li class="active"><a href="#">Home</a></li>
            <li><a href="#about">About</a></li>
            <li><a href="#contact">Contact</a></li>
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown">Dropdown <b class="caret"></b></a>
              <ul class="dropdown-menu">
                <li><a href="#">Action</a></li>
                <li><a href="#">Another action</a></li>
                <li><a href="#">Something else here</a></li>
                <li class="divider"></li>
                <li class="dropdown-header">Nav header</li>
                <li><a href="#">Separated link</a></li>
                <li><a href="#">One more separated link</a></li>
              </ul>
            </li>
          </ul>
        </div><!--/.nav-collapse -->
      </div><!--container-->
    </div><!--navbar-->
  
	   
    <header class="jumbotron subhead" id="overview">
        <div class="container">
            <h1 style="color: #e53333; font-style: normal;font-weight:bold;">Welcome to TAES</h1>
            <p class="lead">Built using Bootstrap</p>
            <ul class="nav nav-pills">
              <li><a href="main.php">Home</a></li>
              <li class="dropdown active">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="#"> ALGORITHM DEMO <span class="caret"></span></a>
                    <ul class="dropdown-menu">
                        <li><a href="demo-zd.php">字典序法</a></li>
                        <li><a href="demo-zj.php">递增进位制法</a></li>
                        <li><a href="demo-jj.php">递减进位制法</a></li>
                        <li><a href="demo-lh.php">邻位对换法</a></li>
                    </ul>
              </li>
              <li><a href="ranking.php">RANKING</a></li>
              <li><a href="evaluation.php">EVALUATION</a></li>
              <li><a href="achievement.php">ACHIEVEMENT</a></li>
            </ul>
        </div>
    </header>
  

    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="https://code.jquery.com/jquery-1.10.2.min.js"></script>
    <script src="dist/js/bootstrap.min.js"></script>
  </body>
</html>
