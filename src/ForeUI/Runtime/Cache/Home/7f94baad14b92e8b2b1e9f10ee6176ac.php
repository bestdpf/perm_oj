<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE HTML>
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
<link href="carousel.css" rel="stylesheet">
<!-- Just for debugging purposes. Don't actually copy this line! -->
<!--[if lt IE 9]><script src="{{ page.base_url }}docs-assets/js/ie8-responsive-file-warning.js"></script><![endif]-->
<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
  <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
<![endif]-->

<!-- 页面header钩子，一般用于加载插件CSS文件和代码 -->
<?php echo hook('pageHeader');?>

</head>
<body>
	<!-- 头部 -->
	<!-- 导航条
================================================== -->
<!-- Fixed navbar -->
 <div class="navbar navbar-inverse navbar-fixed-top">
   <div class="container">
     <div class="navbar-header">
       <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
         <span class="icon-bar"></span>
         <span class="icon-bar"></span>
         <span class="icon-bar"></span>
       </button>
       <a class="navbar-brand" href="<?php echo U('Index/main');?>">TAES Bingo!</a>
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
       
       <?php if(is_login()): ?><ul class="nav navbar-nav navbar-right" style="margin-right:0">
               <li class="dropdown">
                   <a href="#" class="dropdown-toggle" data-toggle="dropdown" style="padding-left:0;padding-right:0"><?php echo get_username();?> <b class="caret"></b></a>
                   <ul class="dropdown-menu">
                       <li><a href="<?php echo U('User/profile');?>" style="font-family: '微软雅黑'">修改密码</a></li>
                       <li><a href="<?php echo U('User/logout');?>" style="font-family: '微软雅黑'">退出</a></li>
                   </ul>
               </li>
           </ul>
       <?php else: ?>
           <ul class="nav navbar-nav navbar-right" style="margin-right:0">
               <li>
                   <a href="<?php echo U('User/login');?>" style="font-family: '微软雅黑'">登录</a>
               </li>
               <li>
                   <a href="<?php echo U('User/register');?>" style="padding-left:0;padding-right:0;font-family: '微软雅黑'">注册</a>
               </li>
           </ul><?php endif; ?>
     </div><!--/.nav-collapse -->
   </div><!--container-->
 </div><!--navbar-->

	<!-- /头部 -->
	
	<!-- 主体 -->
	
    <header class="jumbotron subhead" id="overview">
        <div class="container">
            <h1 style="color: #e53333; font-style: normal;font-weight:bold;">Welcome to TAES</h1>
            <p class="lead">Built using Bootstrap</p>
            <ul class="nav nav-pills">
              <li><a href="<?php echo U('Index/main');?>">Home</a></li>
              <li class="dropdown">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="#"> ALGORITHM DEMO <span class="caret"></span></a>
                    <ul class="dropdown-menu">
                        <li><a href="<?php echo U('FuncPage/demo-zd');?>" style="font-family: '微软雅黑'">字典序法</a></li>
                        <li><a href="<?php echo U('FuncPage/demo-zj');?>" style="font-family: '微软雅黑'">递增进位制法</a></li>
                        <li><a href="<?php echo U('FuncPage/demo-jj');?>" style="font-family: '微软雅黑'">递减进位制法</a></li>
                        <li><a href="<?php echo U('FuncPage/demo-lh');?>" style="font-family: '微软雅黑'">邻位对换法</a></li>
                    </ul>
              </li>
              <li><a href="<?php echo U('FuncPage/ranking');?>">RANKING</a></li>
              <li class="active"><a href="<?php echo U('FuncPage/lastresult');?>">EVALUATION</a></li>
              <li><a href="<?php echo U('FuncPage/achievement');?>">ACHIEVEMENT</a></li>
            </ul>
        </div>
    </header>

<div id="main-container" class="container">
    <div class="row">
        
        <!-- 左侧 nav
        ================================================== -->
            <div class="span3 bs-docs-sidebar">
                
                <ul class="nav nav-list bs-docs-sidenav">
                    <?php echo W('Category/lists', array($category['id'], ACTION_NAME == 'index'));?>
                </ul>
            </div>
        
        
<div class='container' style="color: #e53300 font-style: normal">
	<?php
 $con=mysql_connect("localhost","root","6432114"); if(! $con) die("could not connect：" . mysql_error()); mysql_select_db("judge",$con); $result = mysql_query("SELECT * FROM judge ORDER by runid DESC",$con); echo "<table border='1' width='1200'>
	<tr>
	<th>runid</th>
	<th>usr</th>
	<th>ret</th>
	<th>time</th>
	<th>mem</th>
	</tr>"; while($row = mysql_fetch_array($result)) { echo "<tr align='center'>"; echo "<td>".$row['runid']."</td>"; echo "<td>"."test name"."</td>"; echo "<td>"; if($row['compilecode']!=0){ echo "Compile Error"; } else if($row['RE']!=0){ echo "Runtime Error"; } else if($row['TLE']!=0){ echo "Time Limit Extend"; } else if($row['MLE']!=0){ echo "Memory Limit Extend"; } else if ($row['judgercorrect']!=0){ if($row['judgererrtype']==1){ echo "Less Result"; } else if ($row['judgererrtype']==2){ echo "Dumplicate Result"; } else{ echo "Seqence Error"; } } else { echo "Perfect Code"; } echo "</td>"; echo "<td>".$row['time']."ms</td>"; echo "<td>".$row['mem']."KB</td>"; echo "</tr>"; } ?>
</div>

    </div>
</div>

<script type="text/javascript">
    $(function(){
        $(window).resize(function(){
            $("#main-container").css("min-height", $(window).height() - 343);
        }).resize();
    })
</script>
	<!-- /主体 -->

	<!-- 底部 -->
	<p></p>

<div class="container">
    <!-- FOOTER -->
    <hr class="featurette-divider">
    <footer>
    <p class="pull-right"><a href="#">Back to top</a></p>
    <p class="text-muted credit">本站由 <a href="http://www.bootcss.com/">Bootstrap</a> 及 <a href="http://www.thinkphp.cn/">ThinkPHP</a> 强力驱动.</p>
    </footer>
</div>


<script type="text/javascript">
(function(){
	var ThinkPHP = window.Think = {
		"ROOT"   : "", //当前网站地址
		"APP"    : "/index.php?s=", //当前项目地址
		"PUBLIC" : "/Public", //项目公共目录地址
		"DEEP"   : "<?php echo C('URL_PATHINFO_DEPR');?>", //PATHINFO分割符
		"MODEL"  : ["<?php echo C('URL_MODEL');?>", "<?php echo C('URL_CASE_INSENSITIVE');?>", "<?php echo C('URL_HTML_SUFFIX');?>"],
		"VAR"    : ["<?php echo C('VAR_MODULE');?>", "<?php echo C('VAR_CONTROLLER');?>", "<?php echo C('VAR_ACTION');?>"]
	}
})();
</script>
 <!-- 用于加载js代码 -->
<!-- 页面footer钩子，一般用于加载插件JS文件和JS代码 -->
<?php echo hook('pageFooter', 'widget');?>
<div class="hidden"><!-- 用于加载统计代码等隐藏元素 -->
	
</div>

<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="https://code.jquery.com/jquery-1.10.2.min.js"></script>
<script src="dist/js/bootstrap.min.js"></script>
<script src="js/holder.js"></script>

	<!-- /底部 -->
</body>
</html>