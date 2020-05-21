<%--
  Created by IntelliJ IDEA.
  User: kibeompark
  Date: 2020-05-14
  Time: 23:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form method="get" action="dataset.jsp">
    <p>input the text : <input type="text" id="txt"> </p>

    <p>input password : <input type="password" id="pw"></p>


    <input type="checkbox" name="ck" value="phone">phone
    <input type="checkbox" name="ck" value="computer">computer<br>


    <label for="male">Male</label>
    <input type="radio" name="gender" id="male" value="male">
    <label for="female">Female</label>
    <input type="radio" name="gender" id="female" value="female">


    <p>select color : <input type="color" id="c"></p>

    <p>birthday : <input type="date" id="d"></p>

    <p><input type="range" id="r" min="0" max="10" value="5"></p>

    <p>Quantity (between 1 and 10) :
        <input type="number" id="num" min="1" max="10" value="1" step="1">
    </p>

    <select id="selectbox">
        <option value="select1">select1</option>
        <option value="select2">select2</option>
        <option value="select3">select3</option>
        <option value="select4">select4</option>
    </select>

    <textarea id="textarea" cols="10" rows="5">
	</textarea>

    <input type="submit" value="submit" onclick="printdata()">

</form>
</body>
</html>
