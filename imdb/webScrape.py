import urllib2
from bs4 import BeautifulSoup


d_optMovie= {}
d_movieUrl= {}
print "Search movie name"
movie_name = raw_input();
base_url = "https://www.imdb.com"
find_url = "/find?ref_=nv_sr_fn&q="
searchByTitle = "&s=tt"
comp_url = base_url+find_url+movie_name+searchByTitle

print comp_url

#parse search results for input movie
response = urllib2.urlopen(comp_url)
soup  = BeautifulSoup(response,"lxml")

tag = soup.find('table')
i = 0
print "Displaying results"

for td in tag.find_all('td',class_="result_text"):
		movieName = td.text #Get movie name
		movieLink = td.find('a').attrs['href'] #Get movie Url
		i=i+1
		d_optMovie[i]=movieName #store in dictionary as choice,movie name (key,value)
		d_movieUrl[movieName]= movieLink #store in dictionary as movie name,movie url  (key,value)
		print str(i)+". " + d_optMovie[i]

if (i==0):
	print "No results found"
else:
	print "Please select any number from above results"
	try:
		choice = int(input())
	except ValueError:
		print "Please enter only numbers"
		quit()
	except NameError:
		print "Please enter only numbers"
		quit()
	if (choice ==0 or choice > i):
		print "Invalid input"
		quit()
	selMovie= d_optMovie[choice]
	movie_url = base_url + d_movieUrl[selMovie]
	print movie_url

	#Parse movie url
	response = urllib2.urlopen(movie_url)
	soup  = BeautifulSoup(response,"lxml")
	
	divTag = ""
	for divTag in soup.find_all('div',class_="ratingValue"):
		print "Rating of " + selMovie + " is " + divTag.find('strong').attrs['title']

	if not divTag:
		print "No ratings yet"


