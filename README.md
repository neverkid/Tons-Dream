<h1 style="font-weight:900;color:red;font-size:36px"> Git工具的安装与使用</h1>
<h3 style="font-weight:900;color:rgb(221, 66, 100);font-size:32px;"> Windows环境安装</h3>
<table>
<tr>
<li style=" font-size: 27px; "><b>Windows环境下安装Git工具</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>winget show | findstr Git.Git</i></span><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>winget install Git.Git -l "D:\Program Files\Git "</i></span>
</li>
<li style=" font-size: 27px; "><b>配置git环境变量</b></li>
<li style=" font-size: 27px; "><b>设置Git用户名与邮箱</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git config --global user.name "myname "<br>git config --global user.email myemail@email.com</span></i></li>
<li style=" font-size: 27px; "><b>查看Git状态</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git status</i></span></li>
<li style=" font-size: 27px; "><b>添加当前路径下所有文件</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git add .</i></span></li>
<li style=" font-size: 27px; "><b>查看文件状态</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git status</i></span></li>
<li style=" font-size: 27px; "><b>推送文件到本地仓库</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git commit -m "这里写推送注释"</i></span></li>
<li style=" font-size: 27px; "><b>查看推送结果</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git log</i></span></li>
<li style=" font-size: 27px; "><b>了解Git分支</b><br>
<li style=" font-size: 27px; "><b>查看Git分支信息</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git branch</i></span></li>
<li style=" font-size: 27px; "><b>创建新分支</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git checkout -b "这里写新分支名称"</i></span></li>
<li style=" font-size: 27px; "><b>再次查看Git分支信息</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git branch</i></span></li>
<li style=" font-size: 27px; "><b>切换分支</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git checkout "这里写目标分支名称"</i></span></li>
<li style=" font-size: 27px; "><b>在主分支添加推送信息</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git commit -m "这里写推送注释"</i></span></li>
<li style=" font-size: 27px; "><b>在其他分支查看是否能看到推送信息</b><br>
<span style="font-size: 21px;font-weight:500;color:green;font-family: 'Times New Roman', Times, serif; "><i>git checkout "这里写目标分支名称"<br>git log</i></span></li>
</tr>
</table>

