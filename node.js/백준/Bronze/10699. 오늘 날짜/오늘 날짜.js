const options = {
    timeZone: 'Asia/Seoul',
    year: 'numeric',
    month: '2-digit',
    day: '2-digit'
  };
  
  const today = new Intl.DateTimeFormat('ko-KR', options).format(new Date());
  
  const [year, month, day] = today.split('. ').map(part => part.replace('.', '').trim());
  
  console.log(`${year}-${month}-${day}`);