Coded by 'The Black Cat'<br>
Started : 4/6/2014


<b> Explanation </b>

slow_check creates two sockets<br>
Both without the final CRLF<br>
After 10 seconds, second connection sends additional header<br>
If second connection gets a timeout 10 or more seconds after the first one<br>
That means the server is vulnerable to slowloris type attacks<br>

<b> To-Do-List </b>
<ul>
  <li>~~Use multithreading~~</li> 
  <li>Allow user to modify headers</li>
  <li>Support POST requests</li>
</ul>
