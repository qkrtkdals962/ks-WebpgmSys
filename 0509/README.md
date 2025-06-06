## 유닉스 파일 시스템 구조

- **부트 블록 (Boot Block)**: 부팅 시 사용되는 부트스트랩 코드 저장
- **슈퍼 블록 (Super Block)**: 파일 시스템 전체 정보 포함 (블록 수, i-node 수 등)
- **i-리스트 (i-list)**: i-node들의 목록 (파일 메타데이터 저장)
- **데이터 블록 (Data Block)**: 실제 파일 내용 저장

---

## i-node 구조

- 하나의 파일은 하나의 i-node를 가짐
- 파일 타입, 크기, 권한, 소유자, 블록 포인터 등 메타 정보 포함
- i-node는 데이터 블록을 가리키는 포인터를 가짐:
  - 직접 블록 포인터: 10개
  - 간접/이중 간접 블록 포인터: 2개

---

## 커널의 파일 관리 자료구조

- **fd array**: 프로세스당 파일 디스크립터 배열
- **Open File Table**: 열린 파일 목록 및 현재 오프셋, 플래그 등 관리
- **Active i-node Table**: 열려 있는 파일의 i-node 정보 저장

---

## 주요 시스템 호출 (File 관련)

| 시스템 호출 | 설명 |
|-------------|------|
| `open()`    | 파일 열기, 파일 디스크립터 반환 |
| `read()`    | 파일에서 데이터 읽기 |
| `write()`   | 파일에 데이터 쓰기 |
| `close()`   | 열린 파일 닫기 |
| `lseek()`   | 파일 위치 포인터 이동 |
| `stat()`    | 파일 메타정보 조회 |
| `chmod()`   | 파일 권한 변경 |
| `chown()`   | 소유자, 그룹 변경 |
| `utime()`   | 접근/수정 시간 변경 |
| `link()` / `unlink()` | 하드 링크 생성 / 삭제 |
| `symlink()` / `readlink()` | 심볼릭 링크 생성 / 읽기 |

---

## 파일 타입

- 일반 파일: 텍스트/바이너리 파일
- 디렉터리: 파일 이름과 i-node를 포함
- 문자/블록 장치 파일: 디바이스와 연결
- FIFO, 소켓: 프로세스 간 통신
- 심볼릭 링크: 다른 파일의 경로 참조

---

## 파일 권한

- 사용자/그룹/기타 3단계로 나뉘며 각각 읽기(r), 쓰기(w), 실행(x) 권한 존재
- `chmod`, `chown` 명령어/함수로 변경 가능
- 권한 마스크는 `S_IRUSR`, `S_IWGRP`, `S_IXOTH` 등 사용

---

## 디렉터리 관련 함수

- `opendir()` / `readdir()` / `closedir()` : 디렉터리 열고 엔트리 읽기
- `mkdir()` / `rmdir()` : 디렉터리 생성/삭제
- 디렉터리도 i-node로 표현되며, 내부에는 파일 이름과 i-node 번호가 저장됨

---

## 링크

- **하드 링크 (Hard Link)**: 같은 파일 시스템 내에서 i-node를 공유
- **심볼릭 링크 (Symbolic Link)**: 경로 문자열을 저장, 다른 파일 시스템 가능
- 관련 함수: `link()`, `unlink()`, `symlink()`, `readlink()`

---

## 핵심 요약

- 유닉스 파일 시스템은 계층적 구조로 구성되며, 모든 파일은 i-node로 관리됨
- 시스템 호출을 통해 커널에 파일 접근 요청을 수행함
- 커널 내부에는 다양한 자료구조가 존재하여 파일을 효율적으로 관리함
