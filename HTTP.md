xHTTP notes to make a simple HTTP web server.
First HTTP stands for Hyper Text Transfer Protocol, and the HTTP is an application layer in the OSI model that allows web-based applications to communicate and exchange data.
It is a TCP/IP based protocol and it is used to deliver Content for example images videos audios documents etc..
The client Makes the request and the server is the one that servers in respond into that request.
Main things about HTTP
	1- HTTP is connection-less: after making a request to a server the Client disconnects from the server and when a second request acquires again the connection re-establishes and then sends the respond and then closes.
	2-HTTP can deliverer any sort of data as long as both computers are able to read it.
	3-HTTP is stateless: The client and server know about each  other from reading from the current request and when that connection closes and they want to reconnect they need to provide information again, and the connection is handled as  a first time connection.
Why HTTP in the First Place?
The protocol was designed to only send HTML documents  back in the 90's
but after evolving it support  More features and evolved in general making it the Best way and reliable way to to quickly move and receive data on the web.

The Cycle.
First Thing before the Client sends a request to the server The client needs to already establish a connection with the server that where the internet comes in play. 
Then the Client sends a HTTP  message request defined with some  rules (after all HTTP is a protocol and it needs a set of rules) and disconnects waiting for a respond the server gets the requests prepares the respond and then sends it and disconnects in a form of a HTTP message.
![[http-message.png]]

The information In this 3 sections vary from the type of HTTP message either request or respond Here is a example for it.
![[types-messages.png]]
Let focus on the request msg
-The method tells the Server what it Eg. `GET/POST`
-URL: Is just the path 
-HTTP/version: it just specifies the version and the latest one writing this note is HTTP/3 
But most of web servers Uses HTTP/1.0 or HTTP/1.1
Response HTTP message
-HTTP/version is similar to the one above.
-Status Code: It tells the client The status of their request. Most known ones are 
200(OK (The request is successful )) and  for 404(not-found) there are plenty of them but for now this is enough for us.

To sum this up: 
![[sum.png]]
