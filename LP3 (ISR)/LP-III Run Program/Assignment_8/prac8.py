import requests


def main():
	print("Enter the city name")
	city = input()
	#print(city)
	
	print('Displaying Weater report for: ' + city)
	
	url = 'https://wttr.in/{}'.format(city)
	res = requests.get(url)
	
	print(res.text)

if __name__ == '__main__':
	main()
