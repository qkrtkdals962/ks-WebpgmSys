## 시스템 호출과 파일

- 시스템 호출은 커널에 기능을 요청하는 방식
- 파일을 사용하려면 open으로 열고, read/write로 처리 후 close로 닫음

## 주요 파일 관련 호출

- open: 파일 열기
- creat: 파일 생성
- read / write: 데이터 읽기, 쓰기
- close: 파일 닫기
- dup / dup2: 파일 디스크립터 복제
- lseek: 파일 내 위치 이동

## open의 주요 옵션

- O_RDONLY, O_WRONLY, O_RDWR: 접근 모드
- O_CREAT: 없으면 생성
- O_TRUNC: 기존 내용 삭제
- O_APPEND: 끝에 추가

## 파일 디스크립터

- 열린 파일을 나타내는 정수 번호
- 복제 가능하고 동일한 파일을 공유할 수 있음

## lseek

- 파일 내 읽기/쓰기 위치를 바꿈
- SEEK_SET, SEEK_CUR, SEEK_END 기준 사용
