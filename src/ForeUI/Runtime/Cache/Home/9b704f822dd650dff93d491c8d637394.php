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
    <h2>用户注册</h2>
    <p><span><span class="pull-left"><span>已经有账号? <a href="<?php echo U('Index/index');?>">点此登录</a> </span> </span></p>
  </div>
</header>

<div id="main-container" class="container">
    <div class="row">
         
        

<section>
	<div class="span12">
        <form class="login-form" action="/index.php?s=/home/user/register.html" method="post">
          <div class="control-group">
            <label class="control-label" for="inputEmail">用户名</label>
            <div class="controls">
              <input type="text" id="inputEmail" class="span3" placeholder="请输入用户名"  ajaxurl="/member/checkUserNameUnique.html" errormsg="请填写1-16位用户名" nullmsg="请填写用户名" datatype="*1-16" value="" name="username">
            </div>
          </div>
          <div class="control-group">
            <label class="control-label" for="inputPassword">密码</label>
            <div class="controls">
              <input type="password" id="inputPassword"  class="span3" placeholder="请输入密码"  errormsg="密码为6-20位" nullmsg="请填写密码" datatype="*6-20" name="password">
            </div>
          </div>
          <div class="control-group">
            <label class="control-label" for="inputPassword">确认密码</label>
            <div class="controls">
              <input type="password" id="inputPassword" class="span3" placeholder="请再次输入密码" recheck="password" errormsg="您两次输入的密码不一致" nullmsg="请填确认密码" datatype="*" name="repassword">
            </div>
          </div>
          <div class="control-group">
            <label class="control-label" for="inputEmail">邮箱</label>
            <div class="controls">
              <input type="text" id="inputEmail" class="span3" placeholder="请输入电子邮件"  ajaxurl="/member/checkUserEmailUnique.html" errormsg="请填写正确格式的邮箱" nullmsg="请填写邮箱" datatype="e" value="" name="email">
            </div>
          </div>
          <div class="control-group">
            <label class="control-label" for="inputPassword">验证码</label>
            <div class="controls">
              <input type="text" id="inputPassword" class="span3" placeholder="请输入验证码"  errormsg="请填写5位验证码" nullmsg="请填写验证码" datatype="*5-5" name="verify">
            </div>
          </div>
          <div class="control-group">
            <label class="control-label"></label>
            <div class="controls">
                <img class="verifyimg reloadverify" alt="点击切换" src="<?php echo U('verify');?>" style="cursor:pointer;">
            </div>
            <div class="controls Validform_checktip text-warning"></div>
          </div>
          <div class="control-group">
            <div class="controls">
              <button type="submit" class="btn">注 册</button>
            </div>
          </div>
        </form>
	</div>
</section>


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

	<script type="text/javascript">
    	$(document)
	    	.ajaxStart(function(){
	    		$("button:submit").addClass("log-in").attr("disabled", true);
	    	})
	    	.ajaxStop(function(){
	    		$("button:submit").removeClass("log-in").attr("disabled", false);
	    	});


    	$("form").submit(function(){
    		var self = $(this);
    		$.post(self.attr("action"), self.serialize(), success, "json");
    		return false;

    		function success(data){
    			if(data.status){
    				window.location.href = data.url;
    			} else {
    				self.find(".Validform_checktip").text(data.info);
    				//刷新验证码
    				$(".reloadverify").click();
    			}
    		}
    	});

		$(function(){
			var verifyimg = $(".verifyimg").attr("src");
            $(".reloadverify").click(function(){
                if( verifyimg.indexOf('?')>0){
                    $(".verifyimg").attr("src", verifyimg+'&random='+Math.random());
                }else{
                    $(".verifyimg").attr("src", verifyimg.replace(/\?.*$/,'')+'?'+Math.random());
                }
            });
		});
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